package sjc.test.extended;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.io.StringReader;
import java.util.ArrayList;

import org.eclipse.jdt.core.dom.CompilationUnit;
import org.junit.Assert;
import org.junit.Test;

import sjc.ast.extended.ExtendedASTUtil;
import sjc.symboltable.extended.ExtendedSymbolTable;
import sjc.symboltable.extended.ExtendedSymbolTableBuilder;
import sjc.test.Util;
import sjc.type.TypeFactory;
import sjc.type.checker.extended.ExtendedTypeChecker;
import sjc.type.checker.extended.ExtendedTypeTable;
import sjc.util.Diff;
import sjc.util.DiffPrint;
import sjc.util.Triple;

public class ExtendedTypeCheckingTest {
  private static boolean diff(final Object[] resultStrings,
      final Object[] expectedStrings) {
    final Diff diff = new Diff(resultStrings, expectedStrings);
    final Diff.change script = diff.diff_2(false);
    final DiffPrint.Base p = new DiffPrint.UnifiedPrint(resultStrings,
        expectedStrings);
    if (script == null) {
      System.out.println("OK");
      return true;
    } else {
      p.setOutput(new PrintWriter(System.out));
      p.print_script(script);
      System.err.flush();
      return false;
    }
  }

  private static Object[] getExpectedStrings(final String filePath)
      throws Exception {
    final ArrayList<Object> list = new ArrayList<Object>();
    final FileReader fr = new FileReader(filePath + ".etc");
    final BufferedReader br = new BufferedReader(fr);
    String temp = br.readLine();
    while (temp != null) {
      list.add(temp);
      temp = br.readLine();
    }
    fr.close();
    return list.toArray();
  }

  private static Object[] getLines(final String s) throws Exception {
    final ArrayList<Object> list = new ArrayList<Object>();
    final BufferedReader br = new BufferedReader(new StringReader(s));
    String temp = br.readLine();
    while (temp != null) {
      list.add(temp);
      temp = br.readLine();
    }
    br.close();
    return list.toArray();
  }

  public static void testFail(final String filename) {
    System.out.println("*** Begin testing: " + filename);
    String filePath = null;
    try {
      filePath = typeCheck(filename).first;
      System.out.println("Unexpected type checker to successfully pass "
          + filename);
      System.out.println("*** End FAILING testing: " + filename);
      System.out.println();
      System.out.flush();
      Assert.assertTrue(false);
    } catch (final Throwable e) {
      try {
        final Object[] expectedStrings = ExtendedTypeCheckingTest
            .getExpectedStrings(filePath);
        final Object[] resultStrings = ExtendedTypeCheckingTest.getLines(e
            .getMessage());
        final boolean b = ExtendedTypeCheckingTest.diff(
            resultStrings,
            expectedStrings);
        if (!b) {
          System.out.println("*** End FAILING testing: " + filename);
          System.out.println();
          System.out.flush();
          Assert.assertTrue(false);
        } else {
          System.out.println("*** End PASSING testing: " + filename);
          System.out.println();
          System.out.flush();
        }
      } catch (final Exception e2) {
        System.out.println("Unexpected exception caught while processing "
            + filename);
        System.out.println("Reason: " + e);
        System.out.println("*** End FAILING testing: " + filename);
        System.out.println();
        System.out.flush();
        Assert.assertTrue(e.getMessage(), true);
      }
      System.out.flush();
    }
  }

  public static void testPass(final String filename) {
    System.out.println("*** Begin testing: " + filename);
    String result;
    try {
      final Triple<String, ExtendedSymbolTable, ExtendedTypeTable> t = typeCheck(filename);
      result = t.second.toString() + '\n' + t.third.toString();
      final Object[] expectedStrings = ExtendedTypeCheckingTest
          .getExpectedStrings(t.first);
      final Object[] resultStrings = ExtendedTypeCheckingTest.getLines(result);
      final boolean b = ExtendedTypeCheckingTest.diff(
          resultStrings,
          expectedStrings);
      if (!b) {
        System.out.println("*** End FAILING testing: " + filename);
        System.out.println();
        System.out.flush();
        Assert.assertTrue(false);
      } else {
        System.out.println("*** End PASSING testing: " + filename);
        System.out.println();
        System.out.flush();
      }
    } catch (final Throwable e) {
      System.out.println("Unexpected exception caught while processing "
          + filename);
      System.out.println("Reason: " + e);
      System.out.println("*** End FAILING testing: " + filename);
      System.out.println();
      System.out.flush();
      Assert.assertTrue(e.getMessage(), false);
    }
  }

  private static String PrettyPrint(Object[] strings)
  {
	  String result = "";
	  for(Object o : strings)
	  {
		  result += o.toString() + "\n";
	  }
	  
	  return result;
  }
  
  private static Triple<String, ExtendedSymbolTable, ExtendedTypeTable> typeCheck(
      final String filename) throws Exception {
    final String filePath = Util.getResource(
        ExtendedTypeCheckingTest.class,
        "../../..",
        filename);
    final CompilationUnit cu = ExtendedASTUtil.ast(filePath);

    final TypeFactory tf = new TypeFactory();
    final ExtendedSymbolTable est = ExtendedSymbolTableBuilder.build(cu);
    return new Triple<String, ExtendedSymbolTable, ExtendedTypeTable>(filePath,
        est, ExtendedTypeChecker.check(tf, cu, est));
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
  public void testForwardClassRefs() {
    testPass("ForwardClassRefs.java");
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
  public void testTypeCheckFailAssignAnonymousBooleanArrayToBoolean() {
    testFail("TypeCheckFailAssignAnonymousBooleanArrayToBoolean.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousBooleanArrayToInt() {
    testFail("TypeCheckFailAssignAnonymousBooleanArrayToInt.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousBooleanArrayToIntArray() {
    testFail("TypeCheckFailAssignAnonymousBooleanArrayToIntArray.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousBooleanArrayToObject() {
    testFail("TypeCheckFailAssignAnonymousBooleanArrayToObject.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousBooleanArrayToObjectArray() {
    testFail("TypeCheckFailAssignAnonymousBooleanArrayToObjectArray.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousIntArrayToBoolean() {
    testFail("TypeCheckFailAssignAnonymousIntArrayToBoolean.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousIntArrayToBooleanArray() {
    testFail("TypeCheckFailAssignAnonymousIntArrayToBooleanArray.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousIntArrayToInt() {
    testFail("TypeCheckFailAssignAnonymousIntArrayToInt.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousIntArrayToObject() {
    testFail("TypeCheckFailAssignAnonymousIntArrayToObject.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousIntArrayToObjectArray() {
    testFail("TypeCheckFailAssignAnonymousIntArrayToObjectArray.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousObjectAArrayToObjectA() {
    testFail("TypeCheckFailAssignAnonymousObjectAArrayToObjectA.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousObjectAArrayToObjectB() {
    testFail("TypeCheckFailAssignAnonymousObjectAArrayToObjectB.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousObjectAArrayToObjectBArray() {
    testFail("TypeCheckFailAssignAnonymousObjectAArrayToObjectBArray.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousObjectArrayToBoolean() {
    testFail("TypeCheckFailAssignAnonymousObjectArrayToBoolean.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousObjectArrayToBooleanArray() {
    testFail("TypeCheckFailAssignAnonymousObjectArrayToBooleanArray.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousObjectArrayToInt() {
    testFail("TypeCheckFailAssignAnonymousObjectArrayToInt.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousObjectArrayToIntArray() {
    testFail("TypeCheckFailAssignAnonymousObjectArrayToIntArray.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousObjectAToObjectB() {
    testFail("TypeCheckFailAssignAnonymousObjectAToObjectB.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousObjectAToObjectBArray() {
    testFail("TypeCheckFailAssignAnonymousObjectAToObjectBArray.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousObjectToBoolean() {
    testFail("TypeCheckFailAssignAnonymousObjectToBoolean.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousObjectToBooleanArray() {
    testFail("TypeCheckFailAssignAnonymousObjectToBooleanArray.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousObjectToInt() {
    testFail("TypeCheckFailAssignAnonymousObjectToInt.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousObjectToIntArray() {
    testFail("TypeCheckFailAssignAnonymousObjectToIntArray.java");
  }

  @Test
  public void testTypeCheckFailAssignBooleanToInt() {
    testFail("TypeCheckFailAssignBooleanToInt.java");
  }

  @Test
  public void testTypeCheckFailAssignBooleanToIntArray() {
    testFail("TypeCheckFailAssignBooleanToIntArray.java");
  }

  @Test
  public void testTypeCheckFailAssignBooleanToObject() {
    testFail("TypeCheckFailAssignBooleanToObject.java");
  }

  @Test
  public void testTypeCheckFailAssignBooleanToObjectArray() {
    testFail("TypeCheckFailAssignBooleanToObjectArray.java");
  }

  @Test
  public void testTypeCheckFailAssignFalseToInt() {
    testFail("TypeCheckFailAssignFalseToInt.java");
  }

  @Test
  public void testTypeCheckFailAssignFalseToIntArray() {
    testFail("TypeCheckFailAssignFalseToIntArray.java");
  }

  @Test
  public void testTypeCheckFailAssignFalseToObject() {
    testFail("TypeCheckFailAssignFalseToObject.java");
  }

  @Test
  public void testTypeCheckFailAssignFalseToObjectArray() {
    testFail("TypeCheckFailAssignFalseToObjectArray.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedBooleanArrayToBoolean() {
    testFail("TypeCheckFailAssignNamedBooleanArrayToBoolean.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedBooleanArrayToInt() {
    testFail("TypeCheckFailAssignNamedBooleanArrayToInt.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedBooleanArrayToIntArray() {
    testFail("TypeCheckFailAssignNamedBooleanArrayToIntArray.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedBooleanArrayToObject() {
    testFail("TypeCheckFailAssignNamedBooleanArrayToObject.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedBooleanArrayToObjectArray() {
    testFail("TypeCheckFailAssignNamedBooleanArrayToObjectArray.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedIntArrayToBoolean() {
    testFail("TypeCheckFailAssignNamedIntArrayToBoolean.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedIntArrayToBooleanArray() {
    testFail("TypeCheckFailAssignNamedIntArrayToBooleanArray.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedIntArrayToInt() {
    testFail("TypeCheckFailAssignNamedIntArrayToInt.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedIntArrayToObject() {
    testFail("TypeCheckFailAssignNamedIntArrayToObject.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedIntArrayToObjectArray() {
    testFail("TypeCheckFailAssignNamedIntArrayToObjectArray.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedObjectAArrayToObjectA() {
    testFail("TypeCheckFailAssignNamedObjectAArrayToObjectA.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedObjectAArrayToObjectB() {
    testFail("TypeCheckFailAssignNamedObjectAArrayToObjectB.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedObjectAArrayToObjectBArray() {
    testFail("TypeCheckFailAssignNamedObjectAArrayToObjectBArray.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedObjectArrayToBoolean() {
    testFail("TypeCheckFailAssignNamedObjectArrayToBoolean.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedObjectArrayToBooleanArray() {
    testFail("TypeCheckFailAssignNamedObjectArrayToBooleanArray.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedObjectArrayToInt() {
    testFail("TypeCheckFailAssignNamedObjectArrayToInt.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedObjectArrayToIntArray() {
    testFail("TypeCheckFailAssignNamedObjectArrayToIntArray.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedObjectAToObjectB() {
    testFail("TypeCheckFailAssignNamedObjectAToObjectB.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedObjectAToObjectBArray() {
    testFail("TypeCheckFailAssignNamedObjectAToObjectBArray.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedObjectToBoolean() {
    testFail("TypeCheckFailAssignNamedObjectToBoolean.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedObjectToBooleanArray() {
    testFail("TypeCheckFailAssignNamedObjectToBooleanArray.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedObjectToInt() {
    testFail("TypeCheckFailAssignNamedObjectToInt.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedObjectToIntArray() {
    testFail("TypeCheckFailAssignNamedObjectToIntArray.java");
  }

  @Test
  public void testTypeCheckFailAssignTrueToInt() {
    testFail("TypeCheckFailAssignTrueToInt.java");
  }

  @Test
  public void testTypeCheckFailAssignTrueToIntArray() {
    testFail("TypeCheckFailAssignTrueToIntArray.java");
  }

  @Test
  public void testTypeCheckFailAssignTrueToObject() {
    testFail("TypeCheckFailAssignTrueToObject.java");
  }

  @Test
  public void testTypeCheckFailAssignTrueToObjectArray() {
    testFail("TypeCheckFailAssignTrueToObjectArray.java");
  }

  @Test
  public void testTypeCheckFailBooleanArrayWithBooleanAccess() {
    testFail("TypeCheckFailBooleanArrayWithBooleanAccess.java");
  }

  @Test
  public void testTypeCheckFailComplementBadExpression() {
    testFail("TypeCheckFailComplementBadExpression.java");
  }

  @Test
  public void testTypeCheckFailComplementBoolean() {
    testFail("TypeCheckFailComplementBoolean.java");
  }

  @Test
  public void testTypeCheckFailComplementNull() {
    testFail("TypeCheckFailComplementNull.java");
  }

  @Test
  public void testTypeCheckFailComplementTrue() {
    testFail("TypeCheckFailComplementTrue.java");
  }

  @Test
  public void testTypeCheckFailConditionalAssignIntToBool() {
    testFail("TypeCheckFailConditionalAssignIntToBool.java");
  }

  @Test
  public void testTypeCheckFailConditionalAssignObjectAToObjectAArray() {
    testFail("TypeCheckFailConditionalAssignObjectAToObjectAArray.java");
  }

  @Test
  public void testTypeCheckFailCreateArrayWithBooleanLength() {
    testFail("TypeCheckFailCreateArrayWithBooleanLength.java");
  }

  @Test
  public void testTypeCheckFailCreateArrayWithFalseLength() {
    testFail("TypeCheckFailCreateArrayWithFalseLength.java");
  }

  @Test
  public void testTypeCheckFailCreateIntArrayForBooleanArray() {
    testFail("TypeCheckFailCreateIntArrayForBooleanArray.java");
  }

  @Test
  public void testTypeCheckFailCreateIntArrayForInt() {
    testFail("TypeCheckFailCreateIntArrayForInt.java");
  }

  @Test
  public void testTypeCheckFailCreateIntArrayWithBooleanInitializer() {
    testFail("TypeCheckFailCreateIntArrayWithBooleanInitializer.java");
  }

  @Test
  public void testTypeCheckFailCreateIntArrayWithIntAndBooleanInitializers() {
    testFail("TypeCheckFailCreateIntArrayWithIntAndBooleanInitializers.java");
  }

  @Test
  public void testTypeCheckFailCreateObjectAForObjectAArray() {
    testFail("TypeCheckFailCreateObjectAForObjectAArray.java");
  }

  @Test
  public void testTypeCheckFailCreateObjectBForObjectA() {
    testFail("TypeCheckFailCreateObjectBForObjectA.java");
  }

  @Test
  public void testTypeCheckFailDoWhileWithBooleanArrayCondition() {
    testFail("TypeCheckFailDoWhileWithBooleanArrayCondition.java");
  }

  @Test
  public void testTypeCheckFailForBooleanArrayConditional() {
    testFail("TypeCheckFailForBooleanArrayConditional.java");
  }

  @Test
  public void testTypeCheckFailForIntCondtional() {
    testFail("TypeCheckFailForIntCondtional.java");
  }

  @Test
  public void testTypeCheckFailIncBoolean() {
    testFail("TypeCheckFailIncBoolean.java");
  }

  @Test
  public void testTypeCheckFailIncIntArray() {
    testFail("TypeCheckFailIncIntArray.java");
  }

  @Test
  public void testTypeCheckFailIntArgumentForBooleanParameter() {
    testFail("TypeCheckFailIntArgumentForBooleanParameter.java");
  }

  @Test
  public void testTypeCheckFailIntConditional() {
    testFail("TypeCheckFailIntConditional.java");
  }

  @Test
  public void testTypeCheckFailIntEqualsBoolean() {
    testFail("TypeCheckFailIntEqualsBoolean.java");
  }

  @Test
  public void testTypeCheckFailIntEqualsIntArray() {
    testFail("TypeCheckFailIntEqualsIntArray.java");
  }

  @Test
  public void testTypeCheckFailIntLiteralConditional() {
    testFail("TypeCheckFailIntLiteralConditional.java");
  }

  @Test
  public void testTypeCheckFailIntPlusBadExpression() {
    testFail("TypeCheckFailIntPlusBadExpression.java");
  }

  @Test
  public void testTypeCheckFailIntPlusObject() {
    testFail("TypeCheckFailIntPlusObject.java");
  }

  @Test
  public void testTypeCheckFailNegateBadExpression() {
    testFail("TypeCheckFailNegateBadExpression.java");
  }

  @Test
  public void testTypeCheckFailNegateBoolean() {
    testFail("TypeCheckFailNegateBoolean.java");
  }

  @Test
  public void testTypeCheckFailNegateIntArray() {
    testFail("TypeCheckFailNegateIntArray.java");
  }

  @Test
  public void testTypeCheckFailNegateObject() {
    testFail("TypeCheckFailNegateObject.java");
  }

  @Test
  public void testTypeCheckFailNullEqualsVoid() {
    testFail("TypeCheckFailNullEqualsVoid.java");
  }

  @Test
  public void testTypeCheckFailObjectAEqualsReturnedObjectB() {
    testFail("TypeCheckFailObjectAEqualsReturnedObjectB.java");
  }

  @Test
  public void testTypeCheckFailObjectEqualsBoolean() {
    testFail("TypeCheckFailObjectEqualsBoolean.java");
  }

  @Test
  public void testTypeCheckFailReturnIntFromBooleanMethod() {
    testFail("TypeCheckFailReturnIntFromBooleanMethod.java");
  }

  @Test
  public void testTypeCheckFailReturnIntLiteralFromVoidMethod() {
    testFail("TypeCheckFailReturnIntLiteralFromVoidMethod.java");
  }

  @Test
  public void testTypeCheckFailTooFewMethodArguments() {
    testFail("TypeCheckFailTooFewMethodArguments.java");
  }

  @Test
  public void testTypeCheckFailTooManyMethodArguments() {
    testFail("TypeCheckFailTooManyMethodArguments.java");
  }

  @Test
  public void testTypeCheckFailUndefinedClass() {
    testFail("TypeCheckFailUndefinedClass.java");
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

  @Test
  public void testWhileInitRD() {
    testPass("WhileInitRD.java");
  }

}
