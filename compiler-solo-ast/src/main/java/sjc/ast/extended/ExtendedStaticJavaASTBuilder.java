package sjc.ast.extended;

import java.lang.instrument.ClassDefinition;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

import org.antlr.v4.runtime.ParserRuleContext;
import org.eclipse.jdt.core.dom.AST;
import org.eclipse.jdt.core.dom.ASTNode;
import org.eclipse.jdt.core.dom.AbstractTypeDeclaration;
import org.eclipse.jdt.core.dom.ArrayAccess;
import org.eclipse.jdt.core.dom.ArrayCreation;
import org.eclipse.jdt.core.dom.ArrayInitializer;
import org.eclipse.jdt.core.dom.ArrayType;
import org.eclipse.jdt.core.dom.Assignment;
import org.eclipse.jdt.core.dom.Block;
import org.eclipse.jdt.core.dom.BooleanLiteral;
import org.eclipse.jdt.core.dom.ClassInstanceCreation;
import org.eclipse.jdt.core.dom.CompilationUnit;
import org.eclipse.jdt.core.dom.ConditionalExpression;
import org.eclipse.jdt.core.dom.DoStatement;
import org.eclipse.jdt.core.dom.Expression;
import org.eclipse.jdt.core.dom.ExpressionStatement;
import org.eclipse.jdt.core.dom.FieldAccess;
import org.eclipse.jdt.core.dom.FieldDeclaration;
import org.eclipse.jdt.core.dom.ForStatement;
import org.eclipse.jdt.core.dom.IfStatement;
import org.eclipse.jdt.core.dom.InfixExpression;
import org.eclipse.jdt.core.dom.MethodDeclaration;
import org.eclipse.jdt.core.dom.MethodInvocation;
import org.eclipse.jdt.core.dom.Modifier;
import org.eclipse.jdt.core.dom.Name;
import org.eclipse.jdt.core.dom.NullLiteral;
import org.eclipse.jdt.core.dom.NumberLiteral;
import org.eclipse.jdt.core.dom.ParameterizedType;
import org.eclipse.jdt.core.dom.ParenthesizedExpression;
import org.eclipse.jdt.core.dom.PostfixExpression;
import org.eclipse.jdt.core.dom.PrefixExpression;
import org.eclipse.jdt.core.dom.PrimitiveType;
import org.eclipse.jdt.core.dom.QualifiedName;
import org.eclipse.jdt.core.dom.ReturnStatement;
import org.eclipse.jdt.core.dom.SimpleName;
import org.eclipse.jdt.core.dom.SingleVariableDeclaration;
import org.eclipse.jdt.core.dom.Statement;
import org.eclipse.jdt.core.dom.Type;
import org.eclipse.jdt.core.dom.TypeDeclaration;
import org.eclipse.jdt.core.dom.TypeParameter;
import org.eclipse.jdt.core.dom.VariableDeclarationExpression;
import org.eclipse.jdt.core.dom.VariableDeclarationFragment;
import org.eclipse.jdt.core.dom.VariableDeclarationStatement;
import org.eclipse.jdt.core.dom.WhileStatement;
import org.eclipse.jdt.internal.compiler.ast.BinaryExpression;

import sjc.parser.extended.ExtendedStaticJavaBaseVisitor;
import sjc.parser.extended.ExtendedStaticJavaParser.ArgsContext;
import sjc.parser.extended.ExtendedStaticJavaParser.ArrayAccessExpContext;
import sjc.parser.extended.ExtendedStaticJavaParser.ArrayInitContext;
import sjc.parser.extended.ExtendedStaticJavaParser.ArrayTypeContext;
//import sjc.parser.extended.ExtendedStaticJavaParser.ArrayAccessExpressionContext;
import sjc.parser.extended.ExtendedStaticJavaParser.AssignContext;
import sjc.parser.extended.ExtendedStaticJavaParser.AssignStatementContext;
import sjc.parser.extended.ExtendedStaticJavaParser.BasicTypeContext;
import sjc.parser.extended.ExtendedStaticJavaParser.BinaryExpContext;
//import sjc.parser.extended.ExtendedStaticJavaParser.BinaryExpressionContext;
import sjc.parser.extended.ExtendedStaticJavaParser.BooleanTypeContext;
import sjc.parser.extended.ExtendedStaticJavaParser.ClassDeclarationsContext;
import sjc.parser.extended.ExtendedStaticJavaParser.ClassDefinitionContext;
import sjc.parser.extended.ExtendedStaticJavaParser.CompilationUnitContext;
import sjc.parser.extended.ExtendedStaticJavaParser.CondExpContext;
//import sjc.parser.extended.ExtendedStaticJavaParser.ConditionalExpressionContext;
import sjc.parser.extended.ExtendedStaticJavaParser.DoWhileStatementContext;
//import sjc.parser.extended.ExtendedStaticJavaParser.EmptyExpressionContext;
import sjc.parser.extended.ExtendedStaticJavaParser.ExpContext;
import sjc.parser.extended.ExtendedStaticJavaParser.FalseLiteralContext;
import sjc.parser.extended.ExtendedStaticJavaParser.FieldAccessExpContext;
//import sjc.parser.extended.ExtendedStaticJavaParser.FieldAccessExpressionContext;
import sjc.parser.extended.ExtendedStaticJavaParser.FieldDeclarationContext;
import sjc.parser.extended.ExtendedStaticJavaParser.ForInitsContext;
import sjc.parser.extended.ExtendedStaticJavaParser.ForStatementContext;
import sjc.parser.extended.ExtendedStaticJavaParser.ForUpdatesContext;
import sjc.parser.extended.ExtendedStaticJavaParser.IdExpContext;
import sjc.parser.extended.ExtendedStaticJavaParser.IfStatementContext;
import sjc.parser.extended.ExtendedStaticJavaParser.IncDecContext;
import sjc.parser.extended.ExtendedStaticJavaParser.IncDecStatementContext;
import sjc.parser.extended.ExtendedStaticJavaParser.IntLiteralContext;
import sjc.parser.extended.ExtendedStaticJavaParser.IntTypeContext;
import sjc.parser.extended.ExtendedStaticJavaParser.InvokeContext;
import sjc.parser.extended.ExtendedStaticJavaParser.InvokeExpContext;
import sjc.parser.extended.ExtendedStaticJavaParser.InvokeExpStatementContext;
import sjc.parser.extended.ExtendedStaticJavaParser.LHSArrayAccessContext;
import sjc.parser.extended.ExtendedStaticJavaParser.LHSFieldAccessContext;
import sjc.parser.extended.ExtendedStaticJavaParser.LHSVarRefContext;
//import sjc.parser.extended.ExtendedStaticJavaParser.InvokeExpressionContext;
import sjc.parser.extended.ExtendedStaticJavaParser.LhsContext;
//import sjc.parser.extended.ExtendedStaticJavaParser.LiteralExpressionContext;
import sjc.parser.extended.ExtendedStaticJavaParser.LocalDeclarationContext;
import sjc.parser.extended.ExtendedStaticJavaParser.MainMethodDeclarationContext;
import sjc.parser.extended.ExtendedStaticJavaParser.MethodBodyContext;
import sjc.parser.extended.ExtendedStaticJavaParser.MethodDeclarationContext;
import sjc.parser.extended.ExtendedStaticJavaParser.NewArrayContext;
import sjc.parser.extended.ExtendedStaticJavaParser.NewClassContext;
//import sjc.parser.extended.ExtendedStaticJavaParser.NewExpressionContext;
import sjc.parser.extended.ExtendedStaticJavaParser.NonVoidReturnTypeContext;
import sjc.parser.extended.ExtendedStaticJavaParser.NullLiteralContext;
import sjc.parser.extended.ExtendedStaticJavaParser.ParamContext;
import sjc.parser.extended.ExtendedStaticJavaParser.ParamsContext;
import sjc.parser.extended.ExtendedStaticJavaParser.ParenExpContext;
//import sjc.parser.extended.ExtendedStaticJavaParser.ParenExpressionContext;
import sjc.parser.extended.ExtendedStaticJavaParser.ProgramContext;
import sjc.parser.extended.ExtendedStaticJavaParser.PublicFieldDeclarationContext;
import sjc.parser.extended.ExtendedStaticJavaParser.ReturnStatementContext;
import sjc.parser.extended.ExtendedStaticJavaParser.SimpleClassDeclarationContext;
import sjc.parser.extended.ExtendedStaticJavaParser.SimpleTypeContext;
import sjc.parser.extended.ExtendedStaticJavaParser.StatementContext;
import sjc.parser.extended.ExtendedStaticJavaParser.TrueLiteralContext;
import sjc.parser.extended.ExtendedStaticJavaParser.TypeContext;
import sjc.parser.extended.ExtendedStaticJavaParser.UnaryExpContext;
import sjc.parser.extended.ExtendedStaticJavaParser.VarRefContext;
//import sjc.parser.extended.ExtendedStaticJavaParser.UnaryExpressionContext;
//import sjc.parser.extended.ExtendedStaticJavaParser.VarReferenceContext;
import sjc.parser.extended.ExtendedStaticJavaParser.VoidTypeContext;
import sjc.parser.extended.ExtendedStaticJavaParser.WhileStatementContext;

/**
 * This class builds JDT AST from ANTLR Parse Tree produced by ExtendedStaticJava
 * parser.
 *
 * @author <a href="mailto:robby@cis.ksu.edu">Robby</a>
 */
public class ExtendedStaticJavaASTBuilder extends ExtendedStaticJavaBaseVisitor<ASTNode> {

  static CompilationUnit ast(final CompilationUnitContext ctx) {
    final ExtendedStaticJavaASTBuilder builder = new ExtendedStaticJavaASTBuilder();
    return builder.<CompilationUnit> build(ctx);
  }

  final static HashMap<String, InfixExpression.Operator> binopMap;

  final static HashMap<String, PrefixExpression.Operator> unopMap;
  
  final static HashMap<String, PostfixExpression.Operator> posopMap; 

  static {
    binopMap = new HashMap<String, InfixExpression.Operator>(19);
    ExtendedStaticJavaASTBuilder.binopMap.put("||",InfixExpression.Operator.CONDITIONAL_OR);
    ExtendedStaticJavaASTBuilder.binopMap.put("&&",InfixExpression.Operator.CONDITIONAL_AND);
    ExtendedStaticJavaASTBuilder.binopMap.put("==", InfixExpression.Operator.EQUALS);
    ExtendedStaticJavaASTBuilder.binopMap.put("!=", InfixExpression.Operator.NOT_EQUALS);
    ExtendedStaticJavaASTBuilder.binopMap.put("==", InfixExpression.Operator.EQUALS);
    ExtendedStaticJavaASTBuilder.binopMap.put("<", InfixExpression.Operator.LESS);
    ExtendedStaticJavaASTBuilder.binopMap.put(">", InfixExpression.Operator.GREATER);
    ExtendedStaticJavaASTBuilder.binopMap.put("<=",InfixExpression.Operator.LESS_EQUALS);
    ExtendedStaticJavaASTBuilder.binopMap.put(">=",InfixExpression.Operator.GREATER_EQUALS);
    ExtendedStaticJavaASTBuilder.binopMap.put("+", InfixExpression.Operator.PLUS);
    ExtendedStaticJavaASTBuilder.binopMap.put("-", InfixExpression.Operator.MINUS);
    ExtendedStaticJavaASTBuilder.binopMap.put("*", InfixExpression.Operator.TIMES);
    ExtendedStaticJavaASTBuilder.binopMap.put("/", InfixExpression.Operator.DIVIDE);
    ExtendedStaticJavaASTBuilder.binopMap.put("%", InfixExpression.Operator.REMAINDER);
    ExtendedStaticJavaASTBuilder.binopMap.put(">>", InfixExpression.Operator.RIGHT_SHIFT_SIGNED);
    ExtendedStaticJavaASTBuilder.binopMap.put("<<", InfixExpression.Operator.LEFT_SHIFT);
    ExtendedStaticJavaASTBuilder.binopMap.put(">>>", InfixExpression.Operator.RIGHT_SHIFT_UNSIGNED);

    unopMap = new HashMap<String, PrefixExpression.Operator>(5);
    ExtendedStaticJavaASTBuilder.unopMap.put("+", PrefixExpression.Operator.PLUS);
    ExtendedStaticJavaASTBuilder.unopMap.put("-", PrefixExpression.Operator.MINUS);
    ExtendedStaticJavaASTBuilder.unopMap.put("!", PrefixExpression.Operator.NOT);
    ExtendedStaticJavaASTBuilder.unopMap.put("~", PrefixExpression.Operator.COMPLEMENT);
    
    posopMap = new HashMap<String, PostfixExpression.Operator>(2);
    ExtendedStaticJavaASTBuilder.posopMap.put("++", PostfixExpression.Operator.INCREMENT);
    ExtendedStaticJavaASTBuilder.posopMap.put("--", PostfixExpression.Operator.DECREMENT);
  }

  protected AST ast = AST.newAST(AST.JLS8);

  private ExtendedStaticJavaASTBuilder() {
  }

  @SuppressWarnings("unchecked")
  private void add(@SuppressWarnings("rawtypes") final List l, final Object o) {
    l.add(o);
  }

  @SuppressWarnings("unchecked")
  private <T extends ASTNode> T build(final ParserRuleContext tree) {
    return (T) visit(tree);
  }

  private <E extends ParserRuleContext> void builds(
      @SuppressWarnings("rawtypes") final List l, final List<E> trees) {
    if (trees != null) {
      for (final E e : trees) {
        add(l, build(e));
      }
    }
  }

  @Override
  public ExpressionStatement visitAssignStatement(
      final AssignStatementContext ctx) {
    final Assignment a = this.ast.newAssignment();
    final ExpressionStatement result = this.ast.newExpressionStatement(a);

    indention++;
    Print("Assign Statement");
    
    result.setExpression(this.<Expression> build(ctx.assign()));
    
    Print("returned ExpressionStatement");
		indention--;
    return result;  
    }

  @Override
  public InfixExpression visitBinaryExp(final BinaryExpContext ctx) {
    final InfixExpression result = this.ast.newInfixExpression();

    indention++;
    Print("Binary Expression");
    
    result.setLeftOperand(this.<Expression> build(ctx.e1));
    
    result.setOperator(binopMap.get(ctx.op.getText()));

    result.setRightOperand(this.<Expression> build(ctx.e2));

    Print("returned InfixExpression");
		indention--;
    return result;
  }

  @Override
  public PrimitiveType visitBooleanType(final BooleanTypeContext ctx) {
	  indention++;
	  Print("Boolean Type");
	  final PrimitiveType result = this.ast.newPrimitiveType(PrimitiveType.BOOLEAN);
	  Print("returned PrimitiveType");
		indention--;
    return result;
  }

  @Override
  public TypeDeclaration visitClassDefinition(final ClassDefinitionContext ctx) {
	
	indention++;
	Print("Class Definition");
	
	final TypeDeclaration result = this.ast.newTypeDeclaration();
  
  	add(result.modifiers(),this.ast.newModifier(Modifier.ModifierKeyword.PUBLIC_KEYWORD));

    result.setName(this.ast.newSimpleName(ctx.ID().getText()));

    add(result.bodyDeclarations(), this.<MethodDeclaration> build(ctx.mainMethodDeclaration()));

    final List<ClassDeclarationsContext> classDeclarations = ctx.classDeclarations();
    if(classDeclarations != null)
    	builds(result.bodyDeclarations(), classDeclarations);
    
    Print("returned TypeDeclaration");
		indention--;
    return result;
  }

  @Override
  public CompilationUnit visitCompilationUnit(final CompilationUnitContext ctx) {
	  indention++;
	  Print("Compilation Unit");
	  final CompilationUnit result = this.<CompilationUnit> build(ctx.program());
	  Print("returned CompilationUnit");
		indention--;
	  return result;
  }
  
  @Override
  public BooleanLiteral visitFalseLiteral(final FalseLiteralContext ctx) {
	  indention++;
	  Print("False Literal");
	  final BooleanLiteral result = this.ast.newBooleanLiteral(false);
	  Print("returned BooleanLiteral");
		indention--;
	  return result;
  }

  @Override
  public FieldDeclaration visitFieldDeclaration(final FieldDeclarationContext ctx) {
	  indention++;
	  Print("Field Declaration");
	  
    final VariableDeclarationFragment vdf = this.ast
        .newVariableDeclarationFragment();
    final FieldDeclaration result = this.ast.newFieldDeclaration(vdf);
    add(result.modifiers(), this.ast.newModifier(Modifier.ModifierKeyword.STATIC_KEYWORD));

    result.setType(this.<Type> build(ctx.type()));

    vdf.setName(this.ast.newSimpleName(ctx.ID().getText()));

    Print("returned FieldDeclaration");
		indention--;
    return result;
  }

  @Override
  public SimpleName visitIdExp(final IdExpContext ctx) {
	  indention++;
	  Print("Id Exp");
	  final SimpleName result = this.ast.newSimpleName(ctx.ID().getText());
	  Print("returned SimpleName");
		indention--;
	  return result;
  }

  @Override
  public IfStatement visitIfStatement(final IfStatementContext ctx) {
	indention++;
	Print("If Statement");
	
    final IfStatement result = this.ast.newIfStatement();
    final Block thenBlock = this.ast.newBlock();
    result.setThenStatement(thenBlock);
    final Block elseBlock = this.ast.newBlock();
    result.setElseStatement(elseBlock);

    result.setExpression(this.<Expression> build(ctx.exp()));

    final List<StatementContext> ts = ctx.ts;
    if (ts != null) {
      builds(thenBlock.statements(), ts);
    }

    final List<StatementContext> fs = ctx.fs;
    if (fs != null) {
      builds(elseBlock.statements(), fs);
    }
    
    Print("returned IfStatement");
		indention--;
    return result;
  }

  @Override
  public NumberLiteral visitIntLiteral(final IntLiteralContext ctx) {
	indention++;
	Print("Int Literal");
	
    final NumberLiteral result = this.ast.newNumberLiteral();
    result.setToken(ctx.getText());
    
    Print("returned NumberLiteral");
		indention--;
    return result;
  }

  @Override
  public PrimitiveType visitIntType(final IntTypeContext ctx) {
	  indention++;
	  Print("Int Type");
	  
	  final PrimitiveType result = this.ast.newPrimitiveType(PrimitiveType.INT);
	  
	  Print("returned PrimitiveType");
		indention--;
	  return result;
  }

  @Override
  public MethodInvocation visitInvoke(final InvokeContext ctx) {
	indention++;
	Print("Invoke");
	
    final MethodInvocation result = this.ast.newMethodInvocation();

    if (ctx.id1 != null) {
      result.setExpression(this.ast.newSimpleName(ctx.id1.getText()));
    }

    result.setName(this.ast.newSimpleName(ctx.id2.getText()));

    final ArgsContext args = ctx.args();
    if (args != null) {
      builds(result.arguments(), args.exp());
    }

    Print("returned MethodInvocation");
		indention--;
    return result;
  }

  @Override
  public MethodInvocation visitInvokeExp(final InvokeExpContext ctx) {
	indention++;
	Print("Invoke Exp");
	
	final MethodInvocation result = this.<MethodInvocation> build(ctx.invoke());
	
	Print("returned MethodInvocation");
		indention--;
    return result;
  }

  @Override
  public ExpressionStatement visitInvokeExpStatement(final InvokeExpStatementContext ctx) {
	indention++;
	Print("Invoke Expression Statement");
	
	final ExpressionStatement result = this.ast.newExpressionStatement(this.<MethodInvocation> build(ctx.invoke()));
	
	Print("returned ExpressionStatement");
		indention--;
    return result;
  }

  @Override
  public VariableDeclarationStatement visitLocalDeclaration(final LocalDeclarationContext ctx) {
	indention++;
	Print("Local Declaration");
	
    final VariableDeclarationFragment vdf = this.ast.newVariableDeclarationFragment();
    final VariableDeclarationStatement result = this.ast.newVariableDeclarationStatement(vdf);

    result.setType(this.<Type> build(ctx.type()));

    vdf.setName(this.ast.newSimpleName(ctx.ID().getText()));

    Print("returned VariableDeclarationStatement");
		indention--;
    return result;
  }

  @Override
  public MethodDeclaration visitMainMethodDeclaration(final MainMethodDeclarationContext ctx) {
	indention++;
	Print("Main Method Declaration");
    final MethodDeclaration result = this.ast.newMethodDeclaration();
    add(result.modifiers(),this.ast.newModifier(Modifier.ModifierKeyword.PUBLIC_KEYWORD));
    add(result.modifiers(),this.ast.newModifier(Modifier.ModifierKeyword.STATIC_KEYWORD));
    result.setReturnType2(this.ast.newPrimitiveType(PrimitiveType.VOID));
    result.setName(this.ast.newSimpleName("main"));

    final SingleVariableDeclaration svd = this.ast.newSingleVariableDeclaration();
    svd.setType(this.ast.newArrayType(this.ast.newSimpleType(this.ast.newSimpleName("String"))));
    svd.setName(this.ast.newSimpleName(ctx.id3.getText()));
    add(result.parameters(), svd);

    result.setBody(this.<Block> build(ctx.methodBody()));

    Print("returned MethodDeclaration");
		indention--;
    return result;
  }

  @Override
  public Block visitMethodBody(final MethodBodyContext ctx) {
	indention++;
	Print("Method Body");
	
	final Block result = this.ast.newBlock();

    final List<LocalDeclarationContext> localDeclarations = ctx.localDeclaration();
    if (localDeclarations != null) {
      builds(result.statements(), localDeclarations);
    }

    final List<StatementContext> statements = ctx.statement();
    if (statements != null) {
      builds(result.statements(), statements);
    }

    Print("returned Block");
		indention--;
    return result;
  }

  @Override
  public MethodDeclaration visitMethodDeclaration(final MethodDeclarationContext ctx) {
	indention++;
	Print("Method Declaration");
	
    final MethodDeclaration result = this.ast.newMethodDeclaration();
    add(result.modifiers(),this.ast.newModifier(Modifier.ModifierKeyword.STATIC_KEYWORD));

    result.setReturnType2(this.<Type> build(ctx.returnType()));

    result.setName(this.ast.newSimpleName(ctx.ID().getText()));

    final ParamsContext params = ctx.params();
    if (params != null) {
      builds(result.parameters(), params.param());
    }

    result.setBody(this.<Block> build(ctx.methodBody()));

    Print("returned MethodDeclaration");
		indention--;
    return result;
  }

  @Override
  public Type visitNonVoidReturnType(final NonVoidReturnTypeContext ctx) {
	indention++;
	Print("Non-Void Return Type");
	
	final Type result = this.<Type> build(ctx.type());
	
	Print("returned Type");
		indention--;
    return result;
  }

  @Override
  public NullLiteral visitNullLiteral(final NullLiteralContext ctx) {
	indention++;
	Print("Null Literal");
	
	final NullLiteral result = this.ast.newNullLiteral();
	
	Print("returned NullLiteral");
		indention--;
    return result;
  }

  @Override
  public SingleVariableDeclaration visitParam(final ParamContext ctx) {
	indention++;
	Print("Param");
	
    final SingleVariableDeclaration result = this.ast.newSingleVariableDeclaration();

    result.setType(this.<Type> build(ctx.type()));

    result.setName(this.ast.newSimpleName(ctx.ID().getText()));

    Print("returned SingleVariableDeclaration");
		indention--;
    return result;
  }

  @Override
  public ParenthesizedExpression visitParenExp(final ParenExpContext ctx) {
	indention++;
	Print("Parenthesized Expression");
	
    final ParenthesizedExpression result = this.ast.newParenthesizedExpression();

    result.setExpression(this.<Expression> build(ctx.exp()));

    Print("returned ParenthesizedExpression");
		indention--;
    return result;
  }
  
  @Override
  public ReturnStatement visitReturnStatement(final ReturnStatementContext ctx) {
	indention++;
	Print("Return Statement");
	
    final ReturnStatement result = this.ast.newReturnStatement();

    final ExpContext exp = ctx.exp();
    if (exp != null) {
      result.setExpression(this.<Expression> build(exp));
    }

    Print("returned ReturnStatement");
		indention--;
    return result;
  }

  @Override
  public BooleanLiteral visitTrueLiteral(final TrueLiteralContext ctx) {
	indention++;
	Print("True Literal");
	
	final BooleanLiteral result = this.ast.newBooleanLiteral(true);
	
	Print("returned BooleanLiteral");
		indention--;
	return result;
  }
  
  @Override
  public PrefixExpression visitUnaryExp(final UnaryExpContext ctx) {
	indention++;
	Print("Unary Expression");
	
    final PrefixExpression result = this.ast.newPrefixExpression();

    result.setOperator(ExtendedStaticJavaASTBuilder.unopMap.get(ctx.op.getText()));

    result.setOperand(this.<Expression> build(ctx.exp()));

    Print("returned PrefixExpression");
		indention--;
    return result;
  }

  @Override
  public PrimitiveType visitVoidType(final VoidTypeContext ctx) {
	indention++;
	Print("Void Type");
	
	final PrimitiveType result = this.ast.newPrimitiveType(PrimitiveType.VOID);
	
	Print("returned PrimitiveType");
		indention--;
	return result;
  }

  @Override
  public WhileStatement visitWhileStatement(final WhileStatementContext ctx) {
	indention++;
	Print("While Statement");
	
    final WhileStatement result = this.ast.newWhileStatement();
    final Block whileBody = this.ast.newBlock();
    result.setBody(whileBody);

    result.setExpression(this.<Expression> build(ctx.exp()));

    final List<StatementContext> statements = ctx.statement();
    if (statements != null) {
      builds(whileBody.statements(), statements);
    }

    Print("returned WhileStatement");
		indention--;
    return result;
  }
  
  /**
   * 	Mine
   *	The following are visitor methods that I have implemented 
   */
  
  @Override
  public CompilationUnit visitProgram(final ProgramContext ctx)
  {
	  indention++;
	  Print("Program");
	  
	  final CompilationUnit result = this.ast.newCompilationUnit();
	  
	  builds(result.types(), ctx.preDefs);
	  add(result.types(), this.<TypeDeclaration> build(ctx.classDefinition()));
	  builds(result.types(), ctx.postDefs);
	  
	  Print("returned CompilationUnit");
		indention--;
	  return result;
  }

  @Override
  public TypeDeclaration visitSimpleClassDeclaration(final SimpleClassDeclarationContext ctx)
  {
	  indention++;
	  Print("Simple Class Declaration");
	  
	  final TypeDeclaration result = this.ast.newTypeDeclaration();
	  
	  result.setName(this.ast.newSimpleName(ctx.ID().getText()));
	  
	  if(ctx.publicFieldDeclaration() != null)
		  builds(result.bodyDeclarations(), ctx.publicFieldDeclaration());
	  
	  Print("returned TypeDeclaration");
		indention--;
	  return result;
  }
  
  @Override
  public FieldDeclaration visitPublicFieldDeclaration(final PublicFieldDeclarationContext ctx)
  {
	  indention++;
	  Print("Public Field Declaration");
	  
	  final VariableDeclarationFragment vdf = this.ast.newVariableDeclarationFragment();
	  final FieldDeclaration result = this.ast.newFieldDeclaration(vdf);
	  add(result.modifiers(),this.ast.newModifier(Modifier.ModifierKeyword.PUBLIC_KEYWORD));
	
	  result.setType(this.<Type> build(ctx.type()));
	  
	  vdf.setName(this.ast.newSimpleName(ctx.ID().getText()));
	  
	  Print("returned FieldDeclaration");
		indention--;
	  return result;
  }

  @Override
  public ExpressionStatement visitIncDecStatement(final IncDecStatementContext ctx)
  {
	  indention++;
	  Print("Increment/Decrement Statement");
	  
	  final ExpressionStatement result = this.ast.newExpressionStatement(this.<PostfixExpression> build(ctx.incDec()));
	  
	  Print("returned ExpressionStatement");
		indention--;
	  return result;
  }
  
  @Override
  public Assignment visitAssign(final AssignContext ctx)
  {
	  indention++;
	  Print("Assign");
	  
	  final Assignment result = this.ast.newAssignment();
	  
	  result.setLeftHandSide(this.<Expression> build(ctx.lhs()));
	  result.setRightHandSide(this.<Expression> build(ctx.exp()));
	  
	  Print("returned Assignment");
		indention--;
	  return result;
  }
  
  @Override
  public ForStatement visitForStatement(final ForStatementContext ctx)
  {
	  indention++;
	  Print("For Statement");
	  
	  final ForStatement result = this.ast.newForStatement();
	  
	  if(ctx.forInits() != null && ctx.forInits().assign() != null)
		  builds(result.initializers(), ctx.forInits().assign());
		  //add(result.initializers(),this.<VariableDeclarationExpression> build(ctx.forInits()));
	  
	  if(ctx.exp() != null)
		  result.setExpression(this.<Expression> build(ctx.exp()));
	  
	  if(ctx.forUpdates() != null && ctx.forUpdates().incDec() != null)
		  builds(result.updaters(), ctx.forUpdates().incDec());
		  //add(result.updaters(), this.<VariableDeclarationExpression> build(ctx.forUpdates()));
	  
	  final Block block = this.ast.newBlock();
	  final List<StatementContext> statements = ctx.statement();
	  
	  if(statements != null)
		  builds(block.statements(), statements);
	  
	  result.setBody(block);
	  
	  Print("returned ForStatement");
		indention--;
	  return result;
  }
  
  //Probably cannot use Variable Declaration Expression
  @Override
  public VariableDeclarationExpression visitForInits(final ForInitsContext ctx)
  {
	  indention++;
	  Print("For Inits");
	  
	  final VariableDeclarationFragment vdf = this.ast.newVariableDeclarationFragment();
	  final VariableDeclarationExpression result = this.ast.newVariableDeclarationExpression(vdf);
	  
	  final List<AssignContext> assign = ctx.assign();
	  
	  for(int i = 0; i < assign.size(); i++)
	  {
		  final VariableDeclarationFragment fragment = this.ast.newVariableDeclarationFragment();
		  
	  }
	  if(assign != null)
		  builds(result.fragments(), assign);
	  
	  Print("returned Expression");
		indention--;
	  return result;
		  
  }
  
  @Override
  public VariableDeclarationExpression visitForUpdates(final ForUpdatesContext ctx)
  {
	  indention++;
	  Print("For Updates");
	  
	  final VariableDeclarationFragment vdf = this.ast.newVariableDeclarationFragment();
	  final VariableDeclarationExpression result = this.ast.newVariableDeclarationExpression(vdf);
	  
	  final List<IncDecContext> incdec = ctx.incDec();
	  
	  if(incdec != null)
		  builds(result.fragments(), incdec);
	  
	  Print("returned VariableDeclarationExpression");
		indention--;
	  return result;
  }
  
  @Override
  public PostfixExpression visitIncDec(final IncDecContext ctx)
  {
	  indention++;
	  Print("Increment/Decrement");
	  
	  final PostfixExpression result = this.ast.newPostfixExpression();
	  
	  result.setOperator(posopMap.get(ctx.op.getText()));
	  
	  result.setOperand(this.<Expression> build(ctx.lhs()));
	  
	  Print("returned PostfixExpression");
		indention--;
	  return result;
  }
  
  @Override
  public DoStatement visitDoWhileStatement(final DoWhileStatementContext ctx)
  {
	  indention++;
	  Print("Do-While Statement");
	  
	  final DoStatement result = this.ast.newDoStatement();
	  
	  result.setExpression(this.<Expression> build(ctx.exp()));
	  
	  final Block block = this.ast.newBlock();
	  final List<StatementContext> statements = ctx.statement();
	  
	  if(statements != null)
		  builds(block.statements(), statements);
	  
	  result.setBody(block);
	  
	  Print("returned DoStatement");
		indention--;
	  return result;
  }
  
  @Override
  public ArrayAccess visitArrayAccessExp(final ArrayAccessExpContext ctx)
  {
	  indention++;
	  Print("Array Access Expression");
	  
	  final ArrayAccess result = this.ast.newArrayAccess();
	  
	  result.setArray(this.<Expression> build(ctx.e1));
	  
	  result.setIndex(this.<Expression> build(ctx.e2));
	  
	  Print("returned ArrayAccess");
		indention--;
	  return result;
  }
  
  @Override
  public FieldAccess visitFieldAccessExp(final FieldAccessExpContext ctx)
  {
	  indention++;
	  Print("Field Access Expression");
	  
	  final FieldAccess result = this.ast.newFieldAccess();
	  
	  result.setExpression(this.<Expression> build(ctx.e1));
	  result.setName(this.ast.newSimpleName(ctx.ID().getText()));
	  
	  Print("returned FieldAccess");
		indention--;
	  return result;
  }
  
  @Override
  public ArrayType visitArrayType(final ArrayTypeContext ctx)
  {
	  indention++;
	  Print("Array Type");
	  
	  final Type type;
	  if(ctx.basicType() != null)
		  type = this.<Type> build(ctx.basicType());
	  else
		  type = this.ast.newSimpleType(this.ast.newName(ctx.ID().getText()));
	  
	  final ArrayType result = this.ast.newArrayType(type);
	  
	  Print("returned ArrayType");
		indention--;
	  return result;
  }
  
  @Override
  public Type visitSimpleType(final SimpleTypeContext ctx)
  {
	  indention++;
	  Print("Simple Type");
	  
	  final Type result;
	  
	  if(ctx.basicType() != null)
		  result = this.<Type> build(ctx.basicType());
	  else
		  result = this.ast.newSimpleType(this.ast.newName(ctx.ID().getText()));
	  
	  Print("returned Type");
		indention--;
	  return result;
  }
  
  @Override
  public SimpleName visitLHSVarRef(final LHSVarRefContext ctx)
  {
	  indention++;
	  Print("LHS Variable Reference");
	  final SimpleName result = this.ast.newSimpleName(ctx.getText());
	  Print("returned SimpleName");
		indention--;
	  return result;
  }
  
  @Override
  public ArrayAccess visitLHSArrayAccess(final LHSArrayAccessContext ctx)
  {
	  indention++;
	  Print("Array Access Expression");
	  
	  final ArrayAccess result = this.ast.newArrayAccess();
	  
	  result.setArray(this.<Expression> build(ctx.e1));
	  
	  result.setIndex(this.<Expression> build(ctx.e2));
	  
	  Print("returned ArrayAccess");
		indention--;
	  return result;
  }
  
  @Override
  public FieldAccess visitLHSFieldAccess(final LHSFieldAccessContext ctx)
  {
	  indention++;
	  Print("Field Access Expression");
	  
	  final FieldAccess result = this.ast.newFieldAccess();
	  
	  result.setExpression(this.<Expression> build(ctx.e1));
	  result.setName(this.<SimpleName> build(ctx.varRef()));
	  
	  Print("returned FieldAccess");
		indention--;
	  return result;
  }
  
  @Override
  public SimpleName visitVarRef(final VarRefContext ctx)
  {
	  indention++;
	  Print("Variable Reference");
	  
	  final SimpleName result = this.ast.newSimpleName(ctx.ID().getText());
	  
	  Print("returned SimpleName");
		indention--;
	  return result;
  }
  
  @Override
  public ClassInstanceCreation visitNewClass(final NewClassContext ctx)
  {
	  indention++;
	  Print("New Class");
	  
	  final ClassInstanceCreation result = this.ast.newClassInstanceCreation();
	  
	  result.setType(this.ast.newSimpleType(this.ast.newName(ctx.ID().getText())));
	  
	  Print("returned ClassInstanceCreation");
		indention--;
	  return result;
  }
  
  @Override
  public ArrayCreation visitNewArray(final NewArrayContext ctx)
  {
	  indention++;
	  Print("New Array");
	  
	  final ArrayCreation result = this.ast.newArrayCreation();
	  
	  result.setType(this.ast.newArrayType(this.<Type> build(ctx.type())));
	  
	  if(ctx.exp() != null)
		  add(result.dimensions(), this.<Expression> build(ctx.exp()));
	  
	  if(ctx.arrayInit() != null)
		  result.setInitializer(this.<ArrayInitializer> build(ctx.arrayInit()));
	  
	  Print("returned ArrayCreation");
		indention--;
	  return result;
  }
  
  @Override
  public ArrayInitializer visitArrayInit(final ArrayInitContext ctx)
  {
	  indention++;
	  Print("Array Initializer");
	  
	  final ArrayInitializer result = this.ast.newArrayInitializer();
	  
	  List<ExpContext> expressions = ctx.exp();
	  if(expressions != null)
		  builds(result.expressions(), expressions);
	  
	  Print("returned ArrayInitializer");
		indention--;
	  return result;
  }
  
  @Override
  public ConditionalExpression visitCondExp(final CondExpContext ctx)
  {
	  indention++;
	  Print("Conditional Expression");
	  
	  final ConditionalExpression result = this.ast.newConditionalExpression();
	  
	  result.setExpression(this.<Expression> build(ctx.e1));
	  result.setThenExpression(this.<Expression> build(ctx.e2));
	  result.setElseExpression(this.<Expression> build(ctx.e3));
	  
	  Print("returned ConditionalExpression");
		indention--;
	  return result;
  }
  
  public int indention = -1;
  public boolean debug = true;
  public void Print(String text)
  {
	  String output = "";
	  for(int i = 0; i < indention; i++)
	  {
		  output += "\t";
	  }
	  output += "visited " + text;
	  
	  if(debug) System.out.println(output);
  }
  
}
