package sjc.test.extended;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;

import org.eclipse.jdt.core.dom.CompilationUnit;
import org.junit.Assert;
import org.junit.Test;
import org.objectweb.asm.ClassReader;
import org.objectweb.asm.util.TraceClassVisitor;

import sjc.ast.extended.ExtendedASTUtil;
import sjc.codegen.extended.CGenerator;
import sjc.symboltable.extended.ExtendedSymbolTable;
import sjc.symboltable.extended.ExtendedSymbolTableBuilder;
import sjc.test.Util;
import sjc.type.TypeFactory;
import sjc.type.checker.extended.ExtendedTypeChecker;
import sjc.type.checker.extended.ExtendedTypeTable;

public class CGeneratorTest {

	static class CustomClassLoader extends ClassLoader {
		@SuppressWarnings("rawtypes")
		public Class loadClass(final String name, final byte[] bytecodes) {
			return defineClass(name, bytecodes, 0, bytecodes.length);
		}
	}

	static void outputBytecodes(final PrintWriter pw, final byte[] b) {
		final ClassReader cr = new ClassReader(b);
		final TraceClassVisitor tcv = new TraceClassVisitor(pw);
		cr.accept(tcv, ClassReader.SKIP_FRAMES);
		pw.flush();
	}

	public static void testPass(final String filename) {
		try {
			final String filePath = Util.getResource(CGeneratorTest.class,
					"../../..", filename);
			final CompilationUnit cu = ExtendedASTUtil.ast(filePath);
			final ExtendedSymbolTable est = ExtendedSymbolTableBuilder
					.build(cu);
			final ExtendedTypeTable ett = ExtendedTypeChecker.check(
					new TypeFactory(), cu, est);
			final String result = CGenerator.generate(cu, est, ett);

			// FIXME - prints to .c files
			// convert .java to .c and write new files
			String file = filename.substring(0, filename.indexOf('.'));
			File c = new File("ccode/" + file + ".c");
			FileOutputStream cstream = null;
			// intiialize filestreams
			try {
				cstream = new FileOutputStream(c);
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
			// System.out.println(result); //prints ccode to terminal
			cstream.write(result.getBytes());
			cstream.close();

			System.out.println("*** Begin test: " + file);
			InputStream error;
			InputStreamReader isr;
			BufferedReader br;

			// Compiles .c files
			Process c_proc = Runtime.getRuntime().exec(
					"gcc -o ccode/cout/" + file + " ccode/" + file + ".c");

			error = c_proc.getErrorStream();
			isr = new InputStreamReader(error);
			br = new BufferedReader(isr);
			String s;
			
			// must read output from process before it will finish executing
			while ((s = br.readLine()) != null) {
				System.out.println(s);
			}

			// wait for process to finish executing
			c_proc.waitFor();

			// check if it returned properly
			if (c_proc.exitValue() != 0) {
				System.out.println("*** End FAILING to run test rawr: " + file
						+ ".c\n");
				Assert.assertTrue(false);
			}
			
			br.close();
			isr.close();
			error.close();

			// Run cout files
			Process c_run = Runtime.getRuntime().exec("./ccode/cout/" + file);

			error = c_run.getErrorStream();
			isr = new InputStreamReader(error);
			br = new BufferedReader(isr);

			// must read output from process before it will finish executing
			while ((s = br.readLine()) != null) {
				System.out.println(s);
			}

			// wait for process to finish executing
			c_run.waitFor();

			// check if it returned properly
			if (c_run.exitValue() != 0) {
				System.out.println("*** End FAILING to run test: " + file
						+ ".c\n");
				Assert.assertTrue(false);
			}

			br.close();
			isr.close();
			error.close();
			
			// Process j_proc = Runtime.getRuntime().exec("javac -d " +
			// "jclass src/test/resources/" + file + ".java");
			System.out.println("*** End PASSING test: " + file + "\n");
			Assert.assertTrue(true);

		} catch (final Exception e) {
			e.printStackTrace();
			Assert.assertTrue(e.getMessage(), false);
			throw new RuntimeException();
		}
	}

	@Test
	public void testAEEmptyTest() {
		testPass("AEEmptyTest.java");
	}

	@Test
	public void testArrayAccessVariable() {
		testPass("ArrayAccessVariable.java");
	}

	@Test
	public void testArrayCreation() {
		testPass("ArrayCreation.java");
	}

	@Test
	public void testArrayCreation2() {
		testPass("ArrayCreation2.java");
	}

	@Test
	public void testArrayIndex() {
		testPass("ArrayIndex.java");
	}

	@Test
	public void testArrayIndexConstant() {
		testPass("ArrayIndexConstant.java");
	}

	@Test
	public void testAssignNullToObject() {
		testPass("AssignNullToObject.java");
	}

	@Test
	public void testBasicTypes() {
		testPass("BasicTypes.java");
	}

	@Test
	public void testBinaryOps() {
		testPass("BinaryOps.java");
	}

	@Test
	public void testBooleanAnd() {
		testPass("BooleanAnd.java");
	}

	@Test
	public void testBooleanLiteral() {
		testPass("BooleanLiteral.java");
	}

	@Test
	public void testBooleanNot() {
		testPass("BooleanNot.java");
	}

	@Test
	public void testBooleanOr() {
		testPass("BooleanOr.java");
	}

	@Test
	public void testConditionalFalse() {
		testPass("ConditionalFalse.java");
	}

	@Test
	public void testConditionalTrue() {
		testPass("ConditionalTrue.java");
	}

	@Test
	public void testConditionalWithNull() {
		testPass("ConditionalWithNull.java");
	}

	@Test
	public void testCreateIntArrayWithIntAndIntLiteralInitializers() {
		testPass("CreateIntArrayWithIntAndIntLiteralInitializers.java");
	}

	@Test
	public void testDoWhile() {
		testPass("DoWhile.java");
	}

	@Test
	public void testDoWhileWithBooleanArrayAccessCondition() {
		testPass("DoWhileWithBooleanArrayAccessCondition.java");
	}

	@Test
	public void testFactorial() {
		testPass("Factorial.java");
	}

	@Test
	public void testFieldAccess() {
		testPass("FieldAccess.java");
	}

	@Test
	public void testFor() {
		testPass("For.java");
	}

	@Test
	public void testForBooleanArrayAccessConditional() {
		testPass("ForBooleanArrayAccessConditional.java");
	}

	@Test
	public void testForBooleanMemberAccessConditional() {
		testPass("ForBooleanMemberAccessConditional.java");
	}

	@Test
	public void testForCondOnly() {
		testPass("ForCondOnly.java");
	}

	@Test
	public void testForEmpty() {
		testPass("ForEmpty.java");
	}

	@Test
	public void testForFull() {
		testPass("ForFull.java");
	}

	@Test
	public void testForIncOrDecOnly() {
		testPass("ForIncOrDecOnly.java");
	}

	@Test
	public void testForInitOnly() {
		testPass("ForInitOnly.java");
	}

	@Test
	public void testForLoop() {
		testPass("ForLoop.java");
	}

	@Test
	public void testForMissingCond() {
		testPass("ForMissingCond.java");
	}

	@Test
	public void testForMissingIncOrDec() {
		testPass("ForMissingIncOrDec.java");
	}

	@Test
	public void testForMissingInit() {
		testPass("ForMissingInit.java");
	}

	@Test
	public void testForMultipleIncOrDecOnly() {
		testPass("ForMultipleIncOrDecOnly.java");
	}

	@Test
	public void testForMultipleInitAndIncOrDec() {
		testPass("ForMultipleInitAndIncOrDec.java");
	}

	@Test
	public void testForMultipleInitOnly() {
		testPass("ForMultipleInitOnly.java");
	}

	@Test
	public void testForwardClassTest() {
		testPass("ForwardClassTest.java");
	}

	@Test
	public void testIf() {
		testPass("If.java");
	}

	@Test
	public void testIfFalseEmpty() {
		testPass("IfFalseEmpty.java");
	}

	@Test
	public void testIfFalseSingle() {
		testPass("IfFalseSingle.java");
	}

	@Test
	public void testIfFalseSingleElseEmpty() {
		testPass("IfFalseSingleElseEmpty.java");
	}

	@Test
	public void testIfFalseSingleElseMultiple() {
		testPass("IfFalseSingleElseMultiple.java");
	}

	@Test
	public void testIfFalseSingleElseSingle() {
		testPass("IfFalseSingleElseSingle.java");
	}

	@Test
	public void testIfTrueEmpty() {
		testPass("IfTrueEmpty.java");
	}

	@Test
	public void testIfTrueEmptyElseEmpty() {
		testPass("IfTrueEmptyElseEmpty.java");
	}

	@Test
	public void testIfTrueMultiple() {
		testPass("IfTrueMultiple.java");
	}

	@Test
	public void testIfTrueSingle() {
		testPass("IfTrueSingle.java");
	}

	@Test
	public void testIfTrueSingleElseEmpty() {
		testPass("IfTrueSingleElseEmpty.java");
	}

	@Test
	public void testIfTrueSingleElseSingle() {
		testPass("IfTrueSingleElseSingle.java");
	}

	@Test
	public void testIncIntArrayAccess() {
		testPass("IncIntArrayAccess.java");
	}

	@Test
	public void testIntAdd() {
		testPass("IntAdd.java");
	}

	@Test
	public void testIntComplement() {
		testPass("IntComplement.java");
	}

	@Test
	public void testIntDivide() {
		testPass("IntDivide.java");
	}

	@Test
	public void testIntEqual() {
		testPass("IntEqual.java");
	}

	@Test
	public void testIntGreaterThan() {
		testPass("IntGreaterThan.java");
	}

	@Test
	public void testIntGreaterThanOrEqual() {
		testPass("IntGreaterThanOrEqual.java");
	}

	@Test
	public void testIntLessThan() {
		testPass("IntLessThan.java");
	}

	@Test
	public void testIntLessThanOrEqual() {
		testPass("IntLessThanOrEqual.java");
	}

	@Test
	public void testIntMultiply() {
		testPass("IntMultiply.java");
	}

	@Test
	public void testIntNegate() {
		testPass("IntNegate.java");
	}

	@Test
	public void testIntNotEqual() {
		testPass("IntNotEqual.java");
	}

	@Test
	public void testIntPlus() {
		testPass("IntPlus.java");
	}

	@Test
	public void testIntPostDecrement() {
		testPass("IntPostDecrement.java");
	}

	@Test
	public void testIntPostIncrement() {
		testPass("IntPostIncrement.java");
	}

	@Test
	public void testIntRemainder() {
		testPass("IntRemainder.java");
	}

	@Test
	public void testIntShiftLeft() {
		testPass("IntShiftLeft.java");
	}

	@Test
	public void testIntShiftRight() {
		testPass("IntShiftRight.java");
	}

	@Test
	public void testIntSubtract() {
		testPass("IntSubtract.java");
	}

	@Test
	public void testIntUnsignedShiftRight() {
		testPass("IntUnsignedShiftRight.java");
	}

	@Test
	public void testNewBasic() {
		testPass("NewBasic.java");
	}

	@Test
	public void testNewID() {
		testPass("NewID.java");
	}

	@Test
	public void testNullArgumentForIntArrayParameter() {
		testPass("NullArgumentForIntArrayParameter.java");
	}

	@Test
	public void testNullEqualsNull() {
		testPass("NullEqualsNull.java");
	}

	@Test
	public void testObjectAEqualsReturnedObjectA() {
		testPass("ObjectAEqualsReturnedObjectA.java");
	}

	@Test
	public void testParens() {
		testPass("Parens.java");
	}

	@Test
	public void testPower() {
		testPass("Power.java");
	}

	@Test
	public void testQueue() {
		testPass("Queue.java");
	}

	@Test
	public void testReturnNullFromIntArrayMethod() {
		testPass("ReturnNullFromIntArrayMethod.java");
	}

	@Test
	public void testSAExample() {
		testPass("SAExample.java");
	}

	@Test
	public void testSymbolTableTest() {
		testPass("SymbolTableTest.java");
	}

	@Test
	public void testSyntaxTorture() {
		testPass("SyntaxTorture.java");
	}

	@Test
	public void testTypesArray() {
		testPass("TypesArray.java");
	}

	@Test
	public void testTypesBasic() {
		testPass("TypesBasic.java");
	}

	@Test
	public void testTypesID() {
		testPass("TypesID.java");
	}

	@Test
	public void testUnaryOps() {
		testPass("UnaryOps.java");
	}

	@Test
	public void testWhile() {
		testPass("While.java");
	}

}
