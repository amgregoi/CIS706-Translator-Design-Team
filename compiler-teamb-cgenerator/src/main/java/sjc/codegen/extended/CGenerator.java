package sjc.codegen.extended;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.eclipse.jdt.core.dom.ASTNode;
import org.eclipse.jdt.core.dom.ASTVisitor;
import org.eclipse.jdt.core.dom.ArrayAccess;
import org.eclipse.jdt.core.dom.ArrayCreation;
import org.eclipse.jdt.core.dom.Assignment;
import org.eclipse.jdt.core.dom.BooleanLiteral;
import org.eclipse.jdt.core.dom.ClassInstanceCreation;
import org.eclipse.jdt.core.dom.CompilationUnit;
import org.eclipse.jdt.core.dom.ConditionalExpression;
import org.eclipse.jdt.core.dom.DoStatement;
import org.eclipse.jdt.core.dom.FieldAccess;
import org.eclipse.jdt.core.dom.FieldDeclaration;
import org.eclipse.jdt.core.dom.ForStatement;
import org.eclipse.jdt.core.dom.IfStatement;
import org.eclipse.jdt.core.dom.InfixExpression;
import org.eclipse.jdt.core.dom.MethodDeclaration;
import org.eclipse.jdt.core.dom.MethodInvocation;
import org.eclipse.jdt.core.dom.Modifier;
import org.eclipse.jdt.core.dom.NullLiteral;
import org.eclipse.jdt.core.dom.NumberLiteral;
import org.eclipse.jdt.core.dom.PostfixExpression;
import org.eclipse.jdt.core.dom.PrefixExpression;
import org.eclipse.jdt.core.dom.ReturnStatement;
import org.eclipse.jdt.core.dom.SimpleName;
import org.eclipse.jdt.core.dom.SingleVariableDeclaration;
import org.eclipse.jdt.core.dom.VariableDeclarationFragment;
import org.eclipse.jdt.core.dom.VariableDeclarationStatement;
import org.eclipse.jdt.core.dom.Modifier.ModifierKeyword;
import org.eclipse.jdt.core.dom.TypeDeclaration;
import org.eclipse.jdt.core.dom.WhileStatement;

import sjc.annotation.NonNull;
import sjc.annotation.NonNullElements;
import sjc.annotation.ReadOnlyElements;
import sjc.codegen.ByteCodeGenerator;
import sjc.symboltable.extended.ExtendedSymbolTable;
import sjc.type.ArrayType;
import sjc.type.BooleanType;
import sjc.type.IntType;
import sjc.type.Type;
import sjc.type.checker.extended.ExtendedTypeTable;
import sjc.util.Pair;

import org.stringtemplate.v4.*;

/**
 * This class is used to translate an ExtendedStaticJava {@link CompilationUnit}
 * to {@link ExtendedClassByteCodes} that represent a Java 1.5 class files.
 * 
 * @author <a href="mailto:robby@cis.ksu.edu">Robby</a>
 */
public class CGenerator {
	/**
	 * The visitor for {@link ASTNode} to generate bytecodes.
	 * 
	 * @author <a href="mailto:robby@cis.ksu.edu">Robby</a>
	 */
	protected static class Visitor extends ASTVisitor {
		public @NonNullElements Map<String, byte[]> otherClasses = new HashMap<String, byte[]>();

		protected @NonNullElements @ReadOnlyElements Map<String, TypeDeclaration> classMap;

		protected @NonNullElements @ReadOnlyElements Map<Pair<String, String>, FieldDeclaration> fieldMap;

		protected @NonNullElements @ReadOnlyElements Map<ASTNode, Type> typeMap;

		public String includes = ""; // holds includes
		public String methodProtoTypes = ""; // holdes method prototypes
		public String structProtoTypes = ""; // holds struct prtotypes
		public String structs = "";
		public String code = ""; // holds code
		public String ctemp = ""; // temporarily holds code
		public String doublePtrInit = ""; // holds second part of double ptr
											// initialization

		protected STGroup stg;

		protected Visitor(@NonNull final ExtendedSymbolTable st,
				@NonNull final ExtendedTypeTable tt) {
			this.classMap = st.classMap;
			this.fieldMap = st.fieldMap;
			this.typeMap = tt.typeMap;
			stg = new STGroupFile("cStringTemplates.stg", '%', '%');

			includes = "#include <stdlib.h>\n#include <assert.h>\n#include <stdbool.h>";
		}

		protected void dispose() {
			this.classMap = null;
			this.fieldMap = null;
			this.typeMap = null;
			this.stg = null;
			this.includes = "";
			this.methodProtoTypes = "";
			this.structProtoTypes = "";
			this.code = "";
			this.ctemp = "";
			this.structs = "";

		}

		/**
		 * Determines whether a {@link List} of {@link Modifier}s has a public
		 * modifier (a {@link Modifier}'s whose {@link ModifierKeyword} is
		 * {@link ModifierKeyword.PUBLIC_KEYWORD}).
		 * 
		 * @param modifiers
		 * @return True, if the {@link List} contains a public modifier.
		 */
		protected boolean hasPublicModifier(
				@SuppressWarnings("rawtypes") final List modifiers) {
			for (final Object o : modifiers) {
				if ((o instanceof Modifier)
						&& (((Modifier) o).getKeyword() == ModifierKeyword.PUBLIC_KEYWORD)) {
					return true;
				}
			}
			return false;
		}

		public void setCode(String result) {
			this.ctemp += result;
		}

		public String getCode() {
			String c = this.ctemp;
			this.ctemp = "";
			return c;
		}

		public void addStructProto(String proto) {
			this.structProtoTypes += proto + "\n";
		}

		public void addMethodProto(String method) {
			this.methodProtoTypes += method + "\n";
		}

		public boolean primitiveType(String type) {
			if ((type.equals("int") || type.equals("bool")
					|| type.equals("int[]") || type.equals("bool[]")))
				return true;
			return false;
		}

		// TODO: START

		@Override
		public boolean visit(final TypeDeclaration node) {
			ST td = stg.getInstanceOf("typedeclaration");
			String name = node.getName().getIdentifier();
			td.add("tname", name);
			for (final Object o : node.getFields()) {
				((ASTNode) o).accept(this);
				String body = getCode();
				td.add("body", body);
			}
			String c = td.render();
			if (!hasPublicModifier(node.modifiers())) {
				this.structs += "\n" + c;
				// Prototype structs
				ST sp = stg.getInstanceOf("structprototype");
				sp.add("tname", name);
				final String structProto = sp.render();
				addStructProto(structProto);

			}

			for (final Object o : node.getMethods()) {
				((ASTNode) o).accept(this);
				String method = getCode();
				this.code += "\n" + method;
			}
			return false;
		}

		@Override
		public boolean visit(final MethodDeclaration node) {
			ST md = stg.getInstanceOf("methoddeclaration"); // method dec
			ST mp = stg.getInstanceOf("methodprototype"); // method proto

			final String methodName = node.getName().getIdentifier();
			if (methodName.equals("main")) {
				md.add("type", "void");
				md.add("mname", "main");
			} else {
				// set up method
				String type = node.getReturnType2().toString();
				Type t = this.typeMap.get(node);
				if (type.contains("boolean")) {
					type = type.replace("boolean", "bool");
				}
				if (!(primitiveType(type))) {
					type = type + "*";
				}
				if (type.contains("[]")) {
					type = type.replace("[]", "*");
				}
				// method dec
				md.add("type", type);
				md.add("mname", methodName);
				// method prototype
				mp.add("type", type);
				mp.add("mname", methodName);

				for (final Object o : node.parameters()) {
					((ASTNode) o).accept(this);
					final SingleVariableDeclaration vds = (SingleVariableDeclaration) o;
					String temp = getCode();
					final String localName = vds.getName().getIdentifier();
					String ptype = this.typeMap.get(vds).name;

					if (ptype.contains("boolean")) {
						ptype = ptype.replace("boolean", "bool");
					}
					if (!(primitiveType(ptype))) {
						ptype = ptype + "*";
					}
					if (this.typeMap.get(vds) instanceof ArrayType) {
						ptype = ptype.replace("[]", "*");
						mp.add("args", ptype + " " + localName);
						md.add("args", ptype + " " + localName);
					} else {
						mp.add("args", ptype + " " + localName);
						md.add("args", ptype + " " + localName);
					}
				}
				String proto = mp.render();
				addMethodProto(proto);
			}

			// body
			for (final Object o : node.getBody().statements()) {
				if (!(o instanceof VariableDeclarationStatement)) {
					((ASTNode) o).accept(this);
					String body = getCode();
					md.add("body", body);
				} else {
					// variable declarations
					ST fd = stg.getInstanceOf("fielddeclaration");
					final VariableDeclarationStatement vds = (VariableDeclarationStatement) o;
					final VariableDeclarationFragment vdf = (VariableDeclarationFragment) vds
							.fragments().get(0);
					final String localName = vdf.getName().getIdentifier();
					String type = this.typeMap.get(vds).name;
					if (type.contains("boolean")) {
						type = type.replace("boolean", "bool");
					}
					if (!(type.equals("int") || type.equals("bool")
							|| type.equals("int[]") || type.equals("bool[]"))) {
						type = type + "*";
					}
					if (this.typeMap.get(vds) instanceof ArrayType) {
						type = type.replace("[]", "*");
						fd.add("name", localName);
						fd.add("type", type);
					} else {
						fd.add("name", localName);
						fd.add("type", type);
					}
					String c = fd.render();
					md.add("body", c);
				}
			}
			String c = md.render();
			setCode(c);
			return false;
		}

		@Override
		public boolean visit(final FieldDeclaration node) {
			ST fd = stg.getInstanceOf("fielddeclaration");

			String type = this.typeMap.get(node).name;
			((ASTNode) node.fragments().get(0)).accept(this);
			String name = getCode();

			if (type.contains("boolean")) {
				type = type.replace("boolean", "bool");
			}
			if (!(type.equals("int") || type.equals("bool")
					|| type.equals("int[]") || type.equals("bool[]"))) {
				type = type + "*";
			}
			if (this.typeMap.get(node) instanceof ArrayType) {
				type = type.replace("[]", "*");
				fd.add("type", type);
				fd.add("name", name);
			} else {
				fd.add("type", type);
				fd.add("name", name);
			}

			String c = fd.render();
			setCode(c);
			return false;
		}

		@Override
		public boolean visit(final Assignment node) {
			ST a = stg.getInstanceOf("assignment");

			((ASTNode) node.getLeftHandSide()).accept(this);
			String name = getCode();
			((ASTNode) node.getRightHandSide()).accept(this);
			String val = getCode();

			a.add("name", name);
			a.add("val", val);

			if (!doublePtrInit.equals("")) {
				String c = a.render();
				ST a2 = stg.getInstanceOf("assignment");

				a2.add("name", name);
				a2.add("val", doublePtrInit);
				doublePtrInit = "";

				String c2 = a2.render();
				setCode(c + ";\n" + c2);
				return false;
			}

			String c = a.render();
			setCode(c);
			return false;
		}

		@Override
		public boolean visit(final IfStatement node) {
			ST is = stg.getInstanceOf("ifstatement");
			final String prev = getCode() + "\n";

			node.getExpression().accept(this);
			String exp = getCode();
			node.getThenStatement().accept(this);
			String thenBody = getCode();
			node.getElseStatement().accept(this);
			String elseBody = getCode();

			if (!elseBody.equals("")) {
				is.add("elsebody", elseBody);
			}

			is.add("exp", exp);
			is.add("thenbody", thenBody);

			String c = prev + is.render();
			setCode(c);

			return false;
		}

		@Override
		public boolean visit(final ForStatement node) {
			ST fs = stg.getInstanceOf("forstatement");
			final String prev = getCode() + "\n";

			if (node.initializers().size() > 0) {
				for (int i = 0; i < node.initializers().size(); i++) {
					((ASTNode) node.initializers().get(i)).accept(this);
					String decl = getCode();
					decl = decl.replace(" ", "");
					fs.add("decl", decl);
				}
			}

			if (node.getExpression() != null) {
				((ASTNode) node.getExpression()).accept(this);
				final String exp = getCode();
				fs.add("exp", exp);
			}

			if (node.updaters() != null) {
				for (int i = 0; i < node.updaters().size(); i++) {
					((ASTNode) node.updaters().get(i)).accept(this);
					String incdec = getCode();
					incdec = incdec.replace(";", "");
					fs.add("incdec", incdec);
				}
			}

			if (node.getBody() != null) {
				((ASTNode) node.getBody()).accept(this);
				final String body = getCode();
				fs.add("body", body);
			}

			String fors = prev + fs.render();
			setCode(fors);
			return false;
		}

		@Override
		public boolean visit(final BooleanLiteral node) {
			ST bl = stg.getInstanceOf("booleanliteral");

			if (node.booleanValue()) {
				bl.add("bool", "true");
			} else {
				bl.add("bool", "false");
			}

			String c = bl.render();
			setCode(c);
			return false;
		}

		@Override
		public boolean visit(final ReturnStatement node) {
			ST rs = stg.getInstanceOf("returnstatement");
			final String ret;
			if (node.getExpression() != null) {
				node.getExpression().accept(this);
				ret = getCode();
			} else {
				ret = "";
			}
			rs.add("ret", ret);
			final String c = rs.render();
			setCode(c);
			return false;
		}

		@Override
		public boolean visit(final InfixExpression node) {
			ST ie = stg.getInstanceOf("infixexpression");
			final InfixExpression.Operator op = node.getOperator();

			node.getLeftOperand().accept(this);
			String cleft = getCode();
			node.getRightOperand().accept(this);
			final String cright = getCode();

			if (op == InfixExpression.Operator.CONDITIONAL_AND) {
				ie.add("op", "&&");
			} else if (op == InfixExpression.Operator.CONDITIONAL_OR) {
				ie.add("op", "||");
			} else {
				if (op == InfixExpression.Operator.PLUS) {
					ie.add("op", "+");
				} else if (op == InfixExpression.Operator.MINUS) {
					ie.add("op", "-");
				} else if (op == InfixExpression.Operator.TIMES) {
					ie.add("op", "*");
				} else if (op == InfixExpression.Operator.DIVIDE) {
					ie.add("op", "/");
				} else if (op == InfixExpression.Operator.REMAINDER) {
					ie.add("op", "%");
				} else if (op == InfixExpression.Operator.GREATER) {
					ie.add("op", ">");
				} else if (op == InfixExpression.Operator.GREATER_EQUALS) {
					ie.add("op", ">=");
				} else if (op == InfixExpression.Operator.LESS) {
					ie.add("op", "<");
				} else if (op == InfixExpression.Operator.LESS_EQUALS) {
					ie.add("op", "<=");
				} else if (op == InfixExpression.Operator.EQUALS) {
					ie.add("op", "==");
				} else if (op == InfixExpression.Operator.NOT_EQUALS) {
					ie.add("op", "!=");
				} else if (op == InfixExpression.Operator.LEFT_SHIFT) {
					ie.add("op", "<<");
				} else if (op == InfixExpression.Operator.RIGHT_SHIFT_SIGNED) {
					ie.add("op", ">>");
				} else if (op == InfixExpression.Operator.RIGHT_SHIFT_UNSIGNED) {
					ie.add("op", ">>");
					cleft = "(unsigned)" + cleft;
				}
			}
			ie.add("left", cleft);
			ie.add("right", cright);
			final String c = ie.render();
			setCode(c);
			return false;
		}

		@Override
		public boolean visit(final PostfixExpression node) {
			ST pfe = stg.getInstanceOf("postfix");

			node.getOperand().accept(this);
			final String name = getCode();
			final String op = node.getOperator().toString();

			pfe.add("name", name);
			pfe.add("type", op);
			final String c = pfe.render();
			setCode(c);
			return false;
		}

		@Override
		public boolean visit(final PrefixExpression node) {
			ST pfe = stg.getInstanceOf("prefix");

			node.getOperand().accept(this);
			final String name = getCode();
			final String op = node.getOperator().toString();

			pfe.add("name", name + ")");
			pfe.add("type", op + "(");
			final String c = pfe.render();
			setCode(c);

			return false;
		}

		@Override
		public boolean visit(final NumberLiteral node) {
			setCode(node.getToken());
			return false;
		}

		@Override
		public boolean visit(final MethodInvocation node) {

			final String methodName = node.getName().getIdentifier();
			final String prev = getCode() + "\n";
			if (methodName.equals("assertTrue")) {
				for (final Object o : node.arguments()) {
					((ASTNode) o).accept(this);
					ST as = stg.getInstanceOf("assert");

					String exp = getCode();
					if (exp.contains(";")) {
						exp = exp.replace(";", "");
					}

					as.add("exp", exp);
					final String c = prev + as.render();
					setCode(c);
					return false;
				}
			}

			ST mi = stg.getInstanceOf("methodinvoke");

			for (final Object o : node.arguments()) {
				((ASTNode) o).accept(this);
				final String args = getCode();
				mi.add("args", args);
			}
			mi.add("method", methodName);
			String c = prev + mi.render();
			setCode(c);
			return false;
		}

		@Override
		public boolean visit(final FieldAccess node) {
			ST fa = stg.getInstanceOf("fieldaccess");
			node.getExpression().accept(this);
			final String exp = getCode();
			node.getName().accept(this);
			final String id = getCode();

			fa.add("exp", exp);
			fa.add("id", id);

			final String c = fa.render();
			setCode(c);
			return false;
		}

		@Override
		public boolean visit(final ArrayCreation node) {
			ST ac = stg.getInstanceOf("objectcreation");
			ST ac2 = stg.getInstanceOf("arrayinit");
			String type = this.typeMap.get(node).name.replace("[]", "");
			if (type.contains("boolean")) {
				type = type.replace("boolean", "bool");
			}
			ac.add("type", type);
			if (node.dimensions() != null) {
				for (int i = 0; i < node.dimensions().size(); i++) {
					((ASTNode) node.dimensions().get(0)).accept(this);
					final String size = getCode();
					ac.add("size", size);
				}
			}

			if (node.getInitializer() != null) {
				/*
				 * for(int i=0; i<node.getInitializer().expressions().size();
				 * i++) { ((ASTNode) node.getInitializer().expressions().get(i))
				 * .accept(this); final String arg = getCode(); ac.add("args",
				 * arg); }
				 */
				final String size = Integer.toString((node.getInitializer()
						.expressions().size()));
				ac2.add("size", size);
				ac2.add("type", type);
				for (final Object o : node.getInitializer().expressions()) {
					((ASTNode) o).accept(this);
					final String arg = getCode();
					ac2.add("args", arg);
				}
				if (!(type.equals("int") || type.equals("boolean"))) {
					doublePtrInit = ac2.render();
				} else {
					final String c = ac2.render();
					setCode(c);
					return false;
				}

			}

			final String c = ac.render();
			setCode(c);
			return false;
		}

		@Override
		public boolean visit(final ClassInstanceCreation node) {
			ST cic = stg.getInstanceOf("objectcreation");
			final String type = this.typeMap.get(node).toString();

			cic.add("type", type);

			final String c = cic.render();
			setCode(c);
			return false;
		}

		@Override
		public boolean visit(final SimpleName node) {
			setCode(node.getIdentifier());
			return false;
		}

		@Override
		public boolean visit(final ArrayAccess node) {
			ST aa = stg.getInstanceOf("arrayaccess");
			node.getArray().accept(this);
			final String exp = getCode();
			node.getIndex().accept(this);
			String index = getCode();
			if (index.contains(";")) {
				index = index.replace(";", "");
			}

			aa.add("exp", exp);
			aa.add("index", index);

			final String c = aa.render();
			setCode(c);
			return false;
		}

		@Override
		public boolean visit(final ConditionalExpression node) {
			ST ce = stg.getInstanceOf("conditionalexpression");
			node.getExpression().accept(this);
			final String exp = getCode();
			node.getThenExpression().accept(this);
			final String then = getCode();
			node.getElseExpression().accept(this);
			final String elsee = getCode();

			ce.add("exp", exp);
			ce.add("then", then);
			ce.add("elsee", elsee);

			final String c = ce.render();
			setCode(c);
			return false;
		}

		@Override
		public boolean visit(final NullLiteral node) {
			setCode("NULL");
			return false;
		}

		@Override
		public boolean visit(final WhileStatement node) {
			ST ws = stg.getInstanceOf("whilestatement");
			final String prev = getCode();
			node.getExpression().accept(this);
			final String exp = getCode();

			node.getBody().accept(this);
			final String body = getCode();

			ws.add("exp", exp);
			ws.add("body", body);

			final String c = prev + ws.render();
			setCode(c);

			return false;
		}

		@Override
		public boolean visit(final DoStatement node) {
			ST ds = stg.getInstanceOf("dostatement");
			final String prev = getCode() + "\n";
			node.getExpression().accept(this);
			final String exp = getCode();
			node.getBody().accept(this);
			final String body = getCode();

			ds.add("exp", exp);
			ds.add("body", body);

			final String c = prev + ds.render();
			setCode(c);
			return false;
		}

		// TODO: END
	}

	/**
	 * Generates a {@link ExtendedClassByteCodes} that represents the class
	 * files for the given ExtendedStaticJava {@link CompilationUnit} with the
	 * given {@link ExtendedSymbolTable} and {@link ExtendedTypeTable}.
	 * 
	 * @param cu
	 *            The StaticJava {@link CompilationUnit}.
	 * @param st
	 *            The {@link ExtendedSymbolTable} of the {@link CompilationUnit}
	 *            .
	 * @param tt
	 *            The {@link ExtendedTypeTable} of the {@link CompilationUnit}.
	 * @return The {@link ExtendedClassByteCodes} that represents the class
	 *         files for the given ExtendedStaticJava {@link CompilationUnit}
	 *         with the given {@link ExtendedSymbolTable} and
	 *         {@link ExtendedTypeTable}.
	 * @throws ByteCodeGenerator.Error
	 *             If the generator encounter unexpected error.
	 */
	public static @NonNull String generate(@NonNull final CompilationUnit cu,
			@NonNull final ExtendedSymbolTable est,
			@NonNull final ExtendedTypeTable ett)
			throws ByteCodeGenerator.Error {
		assert (cu != null) && (est != null) && (ett != null);

		final Visitor v = new Visitor(est, ett);
		cu.accept(v);

		// whats being put into output file
		final String result = v.includes + "\n\n" + v.structProtoTypes
				+ v.methodProtoTypes + v.structs + v.code;
		v.dispose();
		return result;
	}

	/**
	 * Declared as protected to disallow creation of this object outside from
	 * the methods of this class.
	 */
	protected CGenerator() {
	}
}
