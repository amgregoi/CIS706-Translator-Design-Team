package sjc.type.checker.extended;

import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import org.eclipse.jdt.core.dom.ASTNode;
import org.eclipse.jdt.core.dom.ArrayAccess;
import org.eclipse.jdt.core.dom.ArrayCreation;
import org.eclipse.jdt.core.dom.ArrayInitializer;
import org.eclipse.jdt.core.dom.Assignment;
import org.eclipse.jdt.core.dom.Block;
import org.eclipse.jdt.core.dom.ClassInstanceCreation;
import org.eclipse.jdt.core.dom.CompilationUnit;
import org.eclipse.jdt.core.dom.ConditionalExpression;
import org.eclipse.jdt.core.dom.Expression;
import org.eclipse.jdt.core.dom.ExpressionStatement;
import org.eclipse.jdt.core.dom.FieldAccess;
import org.eclipse.jdt.core.dom.FieldDeclaration;
import org.eclipse.jdt.core.dom.InfixExpression;
import org.eclipse.jdt.core.dom.MethodDeclaration;
import org.eclipse.jdt.core.dom.MethodInvocation;
import org.eclipse.jdt.core.dom.NullLiteral;
import org.eclipse.jdt.core.dom.PostfixExpression;
import org.eclipse.jdt.core.dom.PostfixExpression.Operator;
import org.eclipse.jdt.core.dom.PrefixExpression;
import org.eclipse.jdt.core.dom.PrimitiveType;
import org.eclipse.jdt.core.dom.ReturnStatement;
import org.eclipse.jdt.core.dom.SimpleName;
import org.eclipse.jdt.core.dom.SimpleType;
import org.eclipse.jdt.core.dom.SingleVariableDeclaration;
import org.eclipse.jdt.core.dom.Statement;
import org.eclipse.jdt.core.dom.TypeDeclaration;
import org.eclipse.jdt.core.dom.VariableDeclarationFragment;
import org.eclipse.jdt.core.dom.VariableDeclarationStatement;

import com.sun.org.apache.xalan.internal.xsltc.compiler.util.BooleanType;

import sjc.annotation.NonNull;
import sjc.annotation.NonNullElements;
import sjc.annotation.ReadOnlyElements;
import sjc.symboltable.SymbolTable;
import sjc.symboltable.extended.ExtendedSymbolTable;
import sjc.type.ArrayType;
import sjc.type.ClassType;
import sjc.type.IntType;
import sjc.type.NonPrimitiveType;
import sjc.type.NullType;
import sjc.type.Type;
import sjc.type.TypeFactory;
import sjc.type.checker.TypeChecker;
import sjc.type.checker.TypeChecker.Error;
import sjc.util.Pair;

/**
 * This class is used to type check a ExtendedStaticJava {@link CompilationUnit} with a
 * given {@link SymbolTable}.
 * 
 * @author <a href="mailto:myname@ksu.edu">MyName</a>
 */
public class ExtendedTypeChecker extends TypeChecker {
  /**
   * The visitor for {@link ASTNode} to type check an ExtendedStaticJava
   * {@link CompilationUnit}.
   * 
   * @author <a href="mailto:robby@cis.ksu.edu">Robby</a>
   */
  protected static class Visitor extends TypeChecker.Visitor {
    protected @NonNullElements
    @ReadOnlyElements
    Map<String, TypeDeclaration> classMap;

    protected @NonNullElements
    @ReadOnlyElements
    Map<Pair<String, String>, FieldDeclaration> fieldMap;

    protected Visitor(final TypeFactory tf, final ExtendedSymbolTable est) {
      super(tf, est);
      this.classMap = est.classMap;
      this.fieldMap = est.fieldMap;
      for (final Pair<String, String> p : est.fieldMap.keySet()) {
        final FieldDeclaration fd = est.fieldMap.get(p);
        final Type t = convertType(fd, fd.getType());
        final String className = p.first;
        final String fieldName = p.second;
        final ClassType ct = tf.getClassType(className);
        ct.fieldTypeMap.put(fieldName, t);
      }
    }

    // TODO: Fill in visit methods here.
    @Override
    public boolean visit(final CompilationUnit cu)
    {
    	return true;
    }
    @Override
    public boolean visit(final Block cu)
    {
    	return true;
    }
    @Override
    public boolean visit(final PrimitiveType cu)
    {
    	return true;
    }
    @Override
    public boolean visit(final ReturnStatement rs)
    {
    	return true;
    }
    
    @Override
    public boolean visit(final FieldAccess node)
    {    	
    	node.getExpression().accept(this);
    	Type expressionType = getResult();

    	if(this.tf.getClassType(expressionType.toString()) == null)
    		throw new Error(node, "Unexpected Class: the class '" + expressionType + "' does not exist in this context");
    	
    	TypeDeclaration ct = (TypeDeclaration)classMap.get(expressionType.toString());
    	FieldDeclaration[] fields = ct.getFields();
    	
    	boolean foundField = false;
    	String nodeName = node.getName().toString();
    	
    	for(FieldDeclaration fd: fields)
    	{
    		Type fdType = convertType(node, fd.getType());
    		for(Object fragment: fd.fragments())
    		{
    			VariableDeclarationFragment vdf = (VariableDeclarationFragment)fragment;
    			String vdfName = vdf.getName().toString();
    			if(vdfName.equals(nodeName))
    			{
    				this.symbolMap.put(node, fd);
    				foundField = true;
    				break;
    			}
    		}
    		if(foundField) break;
    	}
    	
    	if(!foundField)
    		throw new Error(node, "Unexpected Field: the field '" + node.getName() + 
    			"' is not a field in class '" + expressionType + "'");
    	
    	
    	FieldDeclaration nodeDeclaration = (FieldDeclaration)this.symbolMap.get(node);
    	Type nodeType = convertType(node, nodeDeclaration.getType());
    	
    	setResult(node, nodeType);
    	
    	return false;
    }
    
    @Override
    public boolean visit(final SimpleName node)
    {
		final ASTNode parent = node.getParent();
		if ((parent instanceof Expression) || (parent instanceof Statement)) {
			final Object o = this.symbolMap.get(node);
			if (o instanceof FieldDeclaration) {
			  final FieldDeclaration fd = (FieldDeclaration) o;
			  setResult(node, convertType(node, fd.getType()));
			} else if (o instanceof SingleVariableDeclaration) {
			  final SingleVariableDeclaration svd = (SingleVariableDeclaration) o;
			  setResult(node, convertType(node, svd.getType()));
			} else if (o instanceof VariableDeclarationStatement) {
			  final VariableDeclarationStatement vds = (VariableDeclarationStatement) o;
			  setResult(node, convertType(node, vds.getType()));
			}
			else {
			  throw new Error(node, "Unexpected SimpleName: \'" + node + "\' in '" + parent + "'");
			}
		}
		return false;
    }
    
    @Override
    public boolean visit(final ExpressionStatement node) {
		final Expression e = node.getExpression();
		e.accept(this);
		if (e instanceof Assignment) {
			// assignment should not have a resulting type.
			assert getResult() == null;
		} else if (e instanceof MethodInvocation) {
			// method invocation's result can be any type (including void)
			// so we can ignore it.
			getResult();
		} else if (e instanceof PostfixExpression){
			assert getResult() == this.tf.Int;
		} else if(e instanceof PrefixExpression){
			Type returnType = getResult();
			assert (returnType == this.tf.Int || returnType == this.tf.Boolean);
		}
		else {
			throw new Error(node, "Unexpected SimpleName: \'" + node + "\'");
		}
		return false;
    }
    
    @Override
    public boolean visit(final PostfixExpression node)
    {
    	final PostfixExpression.Operator operator = node.getOperator();
    	
    	node.getOperand().accept(this);
    	final Type operandType = getResult();
    	
    	if(operator == PostfixExpression.Operator.INCREMENT ||
    			operator == PostfixExpression.Operator.DECREMENT)
    	{
    		if(operandType != this.tf.Int)
    		{
    			throw new Error(node, "Expecting an int type expression left of the \""
    					+operator+"\" in \"" + node + "\"");
    		}
    		setResult(node.getOperand(), this.tf.Int);
    	}
    	else
    	{
    		throw new Error(node, "Unexpected PostfixExpression \'" + node + "\'");
    	}
    	return false;
    }
    
    @Override
    public boolean visit(final PrefixExpression node)
    {
    	Error err = null;
    	try
    	{
    		return super.visit(node);
    	}
    	catch(Error e)
    	{
    		err = e; 
    	}
    	
    	final PrefixExpression.Operator operator = node.getOperator();
    	
    	node.getOperand().accept(this);
    	final Type operandType = getResult();
    	
    	if(operator == PrefixExpression.Operator.COMPLEMENT)
    	{
    		
    		if(operandType != this.tf.Int && operandType != this.tf.Boolean)
    		{
    			throw new Error(node, "Expecting a primitive type expression right of the \""
    					+operator+"\" operator in \"" + node + "\"");
    		}
    		setResult(node, operandType);
    	}
    	else
    	{
    		throw err;
    	}
    	
    	return false;
    }
    
    @Override
    public boolean visit(final ArrayCreation node)
    {
    	final Type arrayType = convertType(node, node.getType().getElementType());
    	
    	if(node.getInitializer() != null)
    	{
	    	node.getInitializer().accept(this);
	    	final Type initializerType = getResult();
	    	
	    	if(arrayType != initializerType)
	    	{
	    		if(arrayType == this.tf.Int || arrayType == this.tf.Boolean)
	    			throw new Error(node, "Type mismatch: Initializer type \'" + 
	    					initializerType + "\' not expected for an array type of \'"
	    					+ arrayType + "\' in node \'" + node + "\'");
	    		if(initializerType == null)
	    		{
	    			ClassType ct = this.tf.getClassType(arrayType.toString());
	    			if(ct == null)
	    			{
	    				throw new Error(node, "The class type '" + this.tf.Null 
    							+ "' does not exist in this context");
	    			}
	    		}
	    		else
	    		{
	    			throw new Error(node, "The types '" + arrayType + "' and '" + initializerType 
    						+ "' are incompatible");
	    		}
	    	}
    	}
    	
    	if(node.dimensions().size() > 0)
    	{
    		for(final Object o: node.dimensions())
    		{
    			Expression e = (Expression) o;
    			e.accept(this);
    			Type expressionType = getResult();
    			
    			if(expressionType != this.tf.Int)
    			{
    				throw new Error(node, "Type Error: Dimensions must be of type '" + this.tf.Int.toString() + "'");
    			}
    		}
    	}
    	
    	setResult(node, convertType(node, node.getType()));
    	
    	return false;
    }
    
    @Override
    public boolean visit(final NullLiteral node)
    {
    	setResult(node, this.tf.Null);
    	return false;
    }

    @Override
    public boolean visit(final ArrayInitializer node)
    {
    	Type initializerType = null;
    	
    	for(Object o: node.expressions())
    	{
    		final Type expressionType;
    		Expression e = (Expression)o;
    		e.accept(this);
    		
    		expressionType = getResult();
    		
    		if(initializerType != expressionType)
    		{
    			if(initializerType == this.tf.Int || initializerType == this.tf.Boolean)
    			{
    				throw new Error(node, "Type mismatch found in '" + node + "': expected type '" + 
    						initializerType + "' but found type '" + expressionType + "'");
    			}
    			/*
    			if(initializerType == this.tf.Null || initializerType == null)
    			{
    				ClassType ct = this.tf.getClassType(expressionType.toString());
    				if(ct == null)
    				{
    					throw new Error(node, "The class type '" + initializerType.toString() 
    							+ "' does not exist in this context");
    				}
    				
    				initializerType = expressionType;
    			}
    			else if(expressionType == this.tf.Null)
    			{
    				ClassType ct = this.tf.getClassType(initializerType.toString());
    				if(ct == null)
    				{
    					throw new Error(node, "The class type '" + initializerType.toString() 
    							+ "' does not exist in this context");
    				}
    			}
    			else
    			{
    				throw new Error(node, "The types '" + initializerType + "' and '" + expressionType 
    						+ "' are incompatible");
    			}
    			*/
    			
    		}
    	}

    	//setResult(node, initializerType);
    	
    	return true;
    }
    
    @Override 
    public boolean visit(final ClassInstanceCreation node)
    {
    	final Type nodeType = convertType(node, node.getType());
    	
    	if(nodeType == this.tf.Int || nodeType == this.tf.Boolean)
    		throw new Error(node, "Cannot instantiate a new class of type '" + nodeType + "'");
    	
    	final ClassType ct = this.tf.getClassType(nodeType.toString());
    	if(ct == null)
    		throw new Error(node, "Class Type '" + ct.toString() + "' is not available in this context");
    	
    	//TODO: check parameter Types
    	
    	symbolMap.putIfAbsent(node, classMap.get(nodeType.toString()));
    	
    	setResult(node, nodeType);
    	
    	return false;
    }

    public boolean visit(final ArrayAccess node)
    {
    	node.getArray().accept(this);
    	final ArrayType arrayType = (ArrayType) getResult();
    	
    	node.getIndex().accept(this);
    	final Type indexType = getResult();
    	
    	//Error Handling
    	if(arrayType.baseType != this.tf.Int && arrayType.baseType != this.tf.Boolean)
    	{
    		ClassType baseClass = this.tf.getClassType(arrayType.baseType.name);
    		
    		if(baseClass == null)
    			throw new Error(node, "Array Type Invalid: Type '" + arrayType.baseType + "' does not exist or cannot be used in this context.");
    	}
    	
    	if(indexType != this.tf.Int)
    	{
    		throw new Error(node, "Type Error: Dimensions must be of type '" + this.tf.Int.toString() + "'");
    	}
    	
    	setResult(node, arrayType.baseType);
    	
		return false;
    }
    
    @Override
    public boolean visit(final InfixExpression node)
    {
    	Error err = null;
    	
    	try
    	{
    		return super.visit(node);
    	}
    	catch(Error e)
    	{
    		err = e;
    	}
    	
    	node.getLeftOperand().accept(this);
    	final Type lhsType = getResult();
    	node.getRightOperand().accept(this);
    	final Type rhsType = getResult();
    	final InfixExpression.Operator op = node.getOperator();
    	
    	if(op == InfixExpression.Operator.RIGHT_SHIFT_UNSIGNED ||
    			op == InfixExpression.Operator.RIGHT_SHIFT_SIGNED ||
    			op == InfixExpression.Operator.LEFT_SHIFT)
    	{
    		if(lhsType != this.tf.Int && lhsType != this.tf.Boolean)
    		{
    			new Error(node, "Left hand side of '" + node + "' should be of type '" + this.tf.Int + "' or '" + this.tf.Boolean + "'");
    		}
    		
    		if(rhsType != this.tf.Int)
    		{
    			new Error(node, "Expecting an int type expression as the right hand operand of '" + op + "' in '" + node + "'");
    		}
    		setResult(node, lhsType);
    	}
    	else if(op == InfixExpression.Operator.EQUALS ||
    			op == InfixExpression.Operator.NOT_EQUALS)
    	{
    		if(lhsType != rhsType)
    		{
    			if(lhsType == this.tf.Int || lhsType == this.tf.Boolean || rhsType == this.tf.Int || rhsType == this.tf.Boolean)
    			{
    				throw err;
    			}
    			else if(lhsType == this.tf.Null || rhsType == this.tf.Null)
    			{
    				ClassType ct = (lhsType == this.tf.Null)?
    						this.tf.getClassType(rhsType.toString()):
    							this.tf.getClassType(lhsType.toString());
    						
    				if(ct == null)
    					throw new Error(node, "Class Type does not exist: The class type '" + rhsType + "' does not exist in this context");
    				
    				setResult(node, this.tf.Boolean);
    			}
    		}
    		else
    		{
    			throw err;
    		}
    	}
    	else
    	{
    		throw err;
    	}
    	
		return false;
    }

    @Override
    public boolean visit(final ConditionalExpression node)
    {
    	node.getExpression().accept(this);
    	Type expressionType = getResult();
    	node.getThenExpression().accept(this);
    	Type thenExpType = getResult();
    	node.getElseExpression().accept(this);
    	Type elseExpType = getResult();
    	
    	assert expressionType == this.tf.Boolean;
    	
    	Type resultType = thenExpType;
    	
    	if(thenExpType != elseExpType)
    	{
    		if(thenExpType == this.tf.Null || elseExpType == this.tf.Null)
    		{
    			ClassType ct = (thenExpType == this.tf.Null)?
    					this.tf.getClassType(elseExpType.toString()):
    						this.tf.getClassType(thenExpType.toString());
    					
    			if(ct == null)
    				throw new Error(node, "Unexpected Class: The class '" + 
    						ct.toString() + "' does not exist in this context.");
    			
    			resultType = ct;
    		}
    	}
    	
    	setResult(node, resultType);
    	return true;
    }

    @Override
    protected Type convertType(final ASTNode node,
        final org.eclipse.jdt.core.dom.Type t) {
      if (t instanceof SimpleType) {
        final SimpleType st = (SimpleType) t;
        final String name = st.getName().getFullyQualifiedName();
        if (this.classMap.containsKey(name)) {
          return this.tf.getClassType(name);
        }
      }
      return super.convertType(node, t);
    }

    @Override
    protected void dispose() {
      super.dispose();

      this.classMap = null;
      this.fieldMap = null;
    }

    @Override
    protected void typeCheckMethodInvocation(final MethodInvocation node,
        final String className, final String methodName, final Type[] argTypes,
        final Method m) {
      @SuppressWarnings("rawtypes")
      final Class[] paramTypeClasses = m.getParameterTypes();
      final int numOfParams = paramTypeClasses.length;
      if (argTypes.length != numOfParams) {
        throw new Error(node, "Wrong number of arguments to invoke method \""
            + methodName + "\" in \"" + node + "\"");
      }
      final List<Type> paramTypes = new ArrayList<Type>();
      for (int i = 0; i < numOfParams; i++) {
        final Type t = convertType(node, paramTypeClasses[i]);
        if ((argTypes[i] instanceof NullType)
            && (t instanceof NonPrimitiveType)) {
          // OK
        } else if (t != argTypes[i]) {
          throw new Error(node, "Type mismatch the " + i + " argument in \""
              + node + "\"");
        }
        paramTypes.add(t);
      }
      final Type returnType = convertType(node, m.getReturnType());
      if (!this.resultMethodTypeMap.containsKey(m)) {
        this.resultMethodTypeMap.put(m, new Pair<Type, List<Type>>(returnType,
            paramTypes));
      }
      setResult(node, returnType);
    }
    
    @Override
    public boolean visit(final Assignment node)
    {
    	Error err = null;
    	try
    	{
    		return super.visit(node);
    	}
    	catch(Error e)
    	{
    		err = e;
    	}
    	
    	node.getLeftHandSide().accept(this);
        final Type lhsType = getResult();
        node.getRightHandSide().accept(this);
        final Type rhsType = getResult();
        
        if(lhsType != rhsType)
        {
        	if(lhsType == this.tf.Null || rhsType == this.tf.Null)
        	{
        		ClassType ct = (lhsType == this.tf.Null)?
        				this.tf.getClassType(rhsType.toString()):
        					this.tf.getClassType(lhsType.toString());
        		
        		if(ct == null)
        			throw err;
        	}
        	else
        	{
        		throw err;
        	}
        }
        else
        {
        	throw err;
        }
    	
		return false;
    }

    @Override
    protected void typeCheckMethodInvocation(final MethodInvocation node,
        final String className, final String methodName, final Type[] argTypes,
        final MethodDeclaration md) {
      final int numOfParams = md.parameters().size();
      if (argTypes.length != numOfParams) {
        throw new Error(node, "Wrong number of arguments to invoke method \""
            + methodName + "\" in \"" + node + "\"");
      }
      for (int i = 0; i < numOfParams; i++) {
        final Type t = convertType(node, ((SingleVariableDeclaration) md
            .parameters().get(i)).getType());
        if ((argTypes[i] instanceof NullType)
            && (t instanceof NonPrimitiveType)) {
          // OK
        } else if (t != argTypes[i]) {
          throw new Error(node, "Type mismatch the " + i + " argument in \""
              + node + "\"");
        }
      }
      final Type returnType = convertType(node, md.getReturnType2());
      setResult(node, returnType);
    }
  }

  /**
   * Type checks an ExtendedStaticJava {@link CompilationUnit} with the given
   * {@link ExtendedSymbolTable} and the given {@link TypeFactory}. It also
   * resolves {@link MethodInvocation} of library call (and put its mapping in
   * the {@link ExtendedSymbolTable}).
   * 
   * @param tf
   *          The {@link TypeFactory}.
   * @param cu
   *          The StaticJava {@link CompilationUnit}.
   * @param symbolTable
   *          The {@link ExtendedSymbolTable} of the {@link CompilationUnit}
   * @return The {@link ExtendedTypeTable}.
   * @throws TypeChecker.Error
   *           If the type checker encounter type error in the
   *           {@link CompilationUnit}.
   */
  public static @NonNull
  ExtendedTypeTable check(@NonNull final TypeFactory tf,
      @NonNull final CompilationUnit cu,
      @NonNull final ExtendedSymbolTable symbolTable) throws TypeChecker.Error {
    assert (tf != null) && (cu != null) && (symbolTable != null);

    final Visitor v = new Visitor(tf, symbolTable);
    cu.accept(v);
    final ExtendedTypeTable result = new ExtendedTypeTable(v.resultTypeMap,
        v.resultMethodTypeMap);
    v.dispose();
    return result;
  }

  /**
   * Declared as protected to disallow creation of this object outside from the
   * methods of this class.
   */
  protected ExtendedTypeChecker() {
  }
}
