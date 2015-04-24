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
import sjc.test.Util;
import sjc.util.Diff;
import sjc.util.DiffPrint;
import sjc.util.Pair;

public class ExtendedASTParserTest {
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

  private static Pair<String, CompilationUnit> parse(final String filename)
      throws Exception {
    final String filePath = Util.getResource(
        ExtendedASTParserTest.class,
        "../../..",
        filename);
    return new Pair<String, CompilationUnit>(filePath,
        ExtendedASTUtil.ast(filePath));
  }

  public static void testFail(final String filename) {
    System.out.println("*** Begin test: " + filename);
    try {
      parse(filename);
      System.out.println("*** End FAILING test: " + filename);
      System.out.println();
      System.out.flush();
      Assert.assertTrue(false);

    } catch (final Exception e) {
      System.out.println("Exception " + e + " caught while processing "
          + filename);
      System.out.println("*** End PASSING test: " + filename);
      System.out.println();
      System.out.flush();

    }
  }

  public static void testPass(final String filename) {
    final PrintWriter pw = new PrintWriter(System.out);
    System.out.println("*** Begin test: " + filename);
    try {
      Object[] expectedStrings;
      final Pair<String, CompilationUnit> p = parse(filename);
      final CompilationUnit cu = p.second;
      final String result = cu.toString();
      {
        final ArrayList<Object> list = new ArrayList<Object>();
        final FileReader fr = new FileReader(p.first + ".ast");
        final BufferedReader br = new BufferedReader(fr);
        String temp = br.readLine();
        while (temp != null) {
          list.add(temp);
          temp = br.readLine();
        }
        expectedStrings = list.toArray();
        fr.close();
      }
      final Object[] resultStrings = ExtendedASTParserTest.getLines(result);
      final Diff diff = new Diff(resultStrings, expectedStrings);
      final Diff.change script = diff.diff_2(false);
      final DiffPrint.Base b = new DiffPrint.UnifiedPrint(resultStrings,
          expectedStrings);
      if (script == null) {
        System.out.println("*** End PASSING test: " + filename);
        System.out.println();
        System.out.flush();
      } else {
        b.setOutput(pw);
        b.print_script(script);
        System.err.flush();
        System.out.println("*** End FAILING testing: " + filename);
        System.out.println();
        System.out.flush();
        Assert.assertTrue("Mismatched AST output", false);
      }

    } catch (final Exception e) {
      System.out.println("Exception " + e + " caught while processing "
          + filename);
      System.out.println("*** End FAILING testing: " + filename);
      System.out.println();
      System.out.flush();
      Assert.assertTrue(e.getMessage(), false);
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
  public void testComplexFieldArrayAccess() {
    testPass("ComplexFieldArrayAccess.java");
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
  public void testParseFailArrayCreation() {
    testFail("ParseFailArrayCreation.java");
  }

  @Test
  public void testParseFailAssignField() {
    testFail("ParseFailAssignField.java");
  }

  @Test
  public void testParseFailClassConstructor() {
    testFail("ParseFailClassConstructor.java");
  }

  @Test
  public void testParseFailClassMethod() {
    testFail("ParseFailClassMethod.java");
  }

  @Test
  public void testParseFailClassPrivate() {
    testFail("ParseFailClassPrivate.java");
  }

  @Test
  public void testParseFailConditional() {
    testFail("ParseFailConditional.java");
  }

  @Test
  public void testParseFailDec() {
    testFail("ParseFailDec.java");
  }

  @Test
  public void testParseFailDerefNull() {
    testFail("ParseFailDerefNull.java");
  }

  @Test
  public void testParseFailFieldAccess() {
    testFail("ParseFailFieldAccess.java");
  }

  @Test
  public void testParseFailFor() {
    testFail("ParseFailFor.java");
  }

  @Test
  public void testParseFailForUpdate() {
    testFail("ParseFailForUpdate.java");
  }

  @Test
  public void testParseFailNestedIfWhile() {
    testFail("ParseFailNestedIfWhile.java");
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
    testPass("TypeCheckFailAssignAnonymousBooleanArrayToBoolean.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousBooleanArrayToInt() {
    testPass("TypeCheckFailAssignAnonymousBooleanArrayToInt.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousBooleanArrayToIntArray() {
    testPass("TypeCheckFailAssignAnonymousBooleanArrayToIntArray.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousBooleanArrayToObject() {
    testPass("TypeCheckFailAssignAnonymousBooleanArrayToObject.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousBooleanArrayToObjectArray() {
    testPass("TypeCheckFailAssignAnonymousBooleanArrayToObjectArray.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousIntArrayToBoolean() {
    testPass("TypeCheckFailAssignAnonymousIntArrayToBoolean.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousIntArrayToBooleanArray() {
    testPass("TypeCheckFailAssignAnonymousIntArrayToBooleanArray.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousIntArrayToInt() {
    testPass("TypeCheckFailAssignAnonymousIntArrayToInt.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousIntArrayToObject() {
    testPass("TypeCheckFailAssignAnonymousIntArrayToObject.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousIntArrayToObjectArray() {
    testPass("TypeCheckFailAssignAnonymousIntArrayToObjectArray.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousObjectAArrayToObjectA() {
    testPass("TypeCheckFailAssignAnonymousObjectAArrayToObjectA.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousObjectAArrayToObjectB() {
    testPass("TypeCheckFailAssignAnonymousObjectAArrayToObjectB.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousObjectAArrayToObjectBArray() {
    testPass("TypeCheckFailAssignAnonymousObjectAArrayToObjectBArray.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousObjectArrayToBoolean() {
    testPass("TypeCheckFailAssignAnonymousObjectArrayToBoolean.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousObjectArrayToBooleanArray() {
    testPass("TypeCheckFailAssignAnonymousObjectArrayToBooleanArray.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousObjectArrayToInt() {
    testPass("TypeCheckFailAssignAnonymousObjectArrayToInt.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousObjectArrayToIntArray() {
    testPass("TypeCheckFailAssignAnonymousObjectArrayToIntArray.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousObjectAToObjectB() {
    testPass("TypeCheckFailAssignAnonymousObjectAToObjectB.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousObjectAToObjectBArray() {
    testPass("TypeCheckFailAssignAnonymousObjectAToObjectBArray.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousObjectToBoolean() {
    testPass("TypeCheckFailAssignAnonymousObjectToBoolean.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousObjectToBooleanArray() {
    testPass("TypeCheckFailAssignAnonymousObjectToBooleanArray.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousObjectToInt() {
    testPass("TypeCheckFailAssignAnonymousObjectToInt.java");
  }

  @Test
  public void testTypeCheckFailAssignAnonymousObjectToIntArray() {
    testPass("TypeCheckFailAssignAnonymousObjectToIntArray.java");
  }

  @Test
  public void testTypeCheckFailAssignBooleanToInt() {
    testPass("TypeCheckFailAssignBooleanToInt.java");
  }

  @Test
  public void testTypeCheckFailAssignBooleanToIntArray() {
    testPass("TypeCheckFailAssignBooleanToIntArray.java");
  }

  @Test
  public void testTypeCheckFailAssignBooleanToObject() {
    testPass("TypeCheckFailAssignBooleanToObject.java");
  }

  @Test
  public void testTypeCheckFailAssignBooleanToObjectArray() {
    testPass("TypeCheckFailAssignBooleanToObjectArray.java");
  }

  @Test
  public void testTypeCheckFailAssignFalseToInt() {
    testPass("TypeCheckFailAssignFalseToInt.java");
  }

  @Test
  public void testTypeCheckFailAssignFalseToIntArray() {
    testPass("TypeCheckFailAssignFalseToIntArray.java");
  }

  @Test
  public void testTypeCheckFailAssignFalseToObject() {
    testPass("TypeCheckFailAssignFalseToObject.java");
  }

  @Test
  public void testTypeCheckFailAssignFalseToObjectArray() {
    testPass("TypeCheckFailAssignFalseToObjectArray.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedBooleanArrayToBoolean() {
    testPass("TypeCheckFailAssignNamedBooleanArrayToBoolean.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedBooleanArrayToInt() {
    testPass("TypeCheckFailAssignNamedBooleanArrayToInt.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedBooleanArrayToIntArray() {
    testPass("TypeCheckFailAssignNamedBooleanArrayToIntArray.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedBooleanArrayToObject() {
    testPass("TypeCheckFailAssignNamedBooleanArrayToObject.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedBooleanArrayToObjectArray() {
    testPass("TypeCheckFailAssignNamedBooleanArrayToObjectArray.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedIntArrayToBoolean() {
    testPass("TypeCheckFailAssignNamedIntArrayToBoolean.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedIntArrayToBooleanArray() {
    testPass("TypeCheckFailAssignNamedIntArrayToBooleanArray.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedIntArrayToInt() {
    testPass("TypeCheckFailAssignNamedIntArrayToInt.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedIntArrayToObject() {
    testPass("TypeCheckFailAssignNamedIntArrayToObject.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedIntArrayToObjectArray() {
    testPass("TypeCheckFailAssignNamedIntArrayToObjectArray.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedObjectAArrayToObjectA() {
    testPass("TypeCheckFailAssignNamedObjectAArrayToObjectA.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedObjectAArrayToObjectB() {
    testPass("TypeCheckFailAssignNamedObjectAArrayToObjectB.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedObjectAArrayToObjectBArray() {
    testPass("TypeCheckFailAssignNamedObjectAArrayToObjectBArray.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedObjectArrayToBoolean() {
    testPass("TypeCheckFailAssignNamedObjectArrayToBoolean.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedObjectArrayToBooleanArray() {
    testPass("TypeCheckFailAssignNamedObjectArrayToBooleanArray.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedObjectArrayToInt() {
    testPass("TypeCheckFailAssignNamedObjectArrayToInt.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedObjectArrayToIntArray() {
    testPass("TypeCheckFailAssignNamedObjectArrayToIntArray.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedObjectAToObjectB() {
    testPass("TypeCheckFailAssignNamedObjectAToObjectB.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedObjectAToObjectBArray() {
    testPass("TypeCheckFailAssignNamedObjectAToObjectBArray.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedObjectToBoolean() {
    testPass("TypeCheckFailAssignNamedObjectToBoolean.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedObjectToBooleanArray() {
    testPass("TypeCheckFailAssignNamedObjectToBooleanArray.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedObjectToInt() {
    testPass("TypeCheckFailAssignNamedObjectToInt.java");
  }

  @Test
  public void testTypeCheckFailAssignNamedObjectToIntArray() {
    testPass("TypeCheckFailAssignNamedObjectToIntArray.java");
  }

  @Test
  public void testTypeCheckFailAssignTrueToInt() {
    testPass("TypeCheckFailAssignTrueToInt.java");
  }

  @Test
  public void testTypeCheckFailAssignTrueToIntArray() {
    testPass("TypeCheckFailAssignTrueToIntArray.java");
  }

  @Test
  public void testTypeCheckFailAssignTrueToObject() {
    testPass("TypeCheckFailAssignTrueToObject.java");
  }

  @Test
  public void testTypeCheckFailAssignTrueToObjectArray() {
    testPass("TypeCheckFailAssignTrueToObjectArray.java");
  }

  @Test
  public void testTypeCheckFailBooleanArrayWithBooleanAccess() {
    testPass("TypeCheckFailBooleanArrayWithBooleanAccess.java");
  }

  @Test
  public void testTypeCheckFailComplementBadExpression() {
    testPass("TypeCheckFailComplementBadExpression.java");
  }

  @Test
  public void testTypeCheckFailComplementBoolean() {
    testPass("TypeCheckFailComplementBoolean.java");
  }

  @Test
  public void testTypeCheckFailComplementNull() {
    testPass("TypeCheckFailComplementNull.java");
  }

  @Test
  public void testTypeCheckFailComplementTrue() {
    testPass("TypeCheckFailComplementTrue.java");
  }

  @Test
  public void testTypeCheckFailConditionalAssignIntToBool() {
    testPass("TypeCheckFailConditionalAssignIntToBool.java");
  }

  @Test
  public void testTypeCheckFailConditionalAssignObjectAToObjectAArray() {
    testPass("TypeCheckFailConditionalAssignObjectAToObjectAArray.java");
  }

  @Test
  public void testTypeCheckFailCreateArrayWithBooleanLength() {
    testPass("TypeCheckFailCreateArrayWithBooleanLength.java");
  }

  @Test
  public void testTypeCheckFailCreateArrayWithFalseLength() {
    testPass("TypeCheckFailCreateArrayWithFalseLength.java");
  }

  @Test
  public void testTypeCheckFailCreateIntArrayForBooleanArray() {
    testPass("TypeCheckFailCreateIntArrayForBooleanArray.java");
  }

  @Test
  public void testTypeCheckFailCreateIntArrayForInt() {
    testPass("TypeCheckFailCreateIntArrayForInt.java");
  }

  @Test
  public void testTypeCheckFailCreateIntArrayWithBooleanInitializer() {
    testPass("TypeCheckFailCreateIntArrayWithBooleanInitializer.java");
  }

  @Test
  public void testTypeCheckFailCreateIntArrayWithIntAndBooleanInitializers() {
    testPass("TypeCheckFailCreateIntArrayWithIntAndBooleanInitializers.java");
  }

  @Test
  public void testTypeCheckFailCreateObjectAForObjectAArray() {
    testPass("TypeCheckFailCreateObjectAForObjectAArray.java");
  }

  @Test
  public void testTypeCheckFailCreateObjectBForObjectA() {
    testPass("TypeCheckFailCreateObjectBForObjectA.java");
  }

  @Test
  public void testTypeCheckFailDoWhileWithBooleanArrayCondition() {
    testPass("TypeCheckFailDoWhileWithBooleanArrayCondition.java");
  }

  @Test
  public void testTypeCheckFailForBooleanArrayConditional() {
    testPass("TypeCheckFailForBooleanArrayConditional.java");
  }

  @Test
  public void testTypeCheckFailForIntCondtional() {
    testPass("TypeCheckFailForIntCondtional.java");
  }

  @Test
  public void testTypeCheckFailIncBoolean() {
    testPass("TypeCheckFailIncBoolean.java");
  }

  @Test
  public void testTypeCheckFailIncIntArray() {
    testPass("TypeCheckFailIncIntArray.java");
  }

  @Test
  public void testTypeCheckFailIntArgumentForBooleanParameter() {
    testPass("TypeCheckFailIntArgumentForBooleanParameter.java");
  }

  @Test
  public void testTypeCheckFailIntConditional() {
    testPass("TypeCheckFailIntConditional.java");
  }

  @Test
  public void testTypeCheckFailIntEqualsBoolean() {
    testPass("TypeCheckFailIntEqualsBoolean.java");
  }

  @Test
  public void testTypeCheckFailIntEqualsIntArray() {
    testPass("TypeCheckFailIntEqualsIntArray.java");
  }

  @Test
  public void testTypeCheckFailIntLiteralConditional() {
    testPass("TypeCheckFailIntLiteralConditional.java");
  }

  @Test
  public void testTypeCheckFailIntPlusBadExpression() {
    testPass("TypeCheckFailIntPlusBadExpression.java");
  }

  @Test
  public void testTypeCheckFailIntPlusObject() {
    testPass("TypeCheckFailIntPlusObject.java");
  }

  @Test
  public void testTypeCheckFailNegateBadExpression() {
    testPass("TypeCheckFailNegateBadExpression.java");
  }

  @Test
  public void testTypeCheckFailNegateBoolean() {
    testPass("TypeCheckFailNegateBoolean.java");
  }

  @Test
  public void testTypeCheckFailNegateIntArray() {
    testPass("TypeCheckFailNegateIntArray.java");
  }

  @Test
  public void testTypeCheckFailNegateObject() {
    testPass("TypeCheckFailNegateObject.java");
  }

  @Test
  public void testTypeCheckFailNullEqualsVoid() {
    testPass("TypeCheckFailNullEqualsVoid.java");
  }

  @Test
  public void testTypeCheckFailObjectAEqualsReturnedObjectB() {
    testPass("TypeCheckFailObjectAEqualsReturnedObjectB.java");
  }

  @Test
  public void testTypeCheckFailObjectEqualsBoolean() {
    testPass("TypeCheckFailObjectEqualsBoolean.java");
  }

  @Test
  public void testTypeCheckFailReturnIntFromBooleanMethod() {
    testPass("TypeCheckFailReturnIntFromBooleanMethod.java");
  }

  @Test
  public void testTypeCheckFailReturnIntLiteralFromVoidMethod() {
    testPass("TypeCheckFailReturnIntLiteralFromVoidMethod.java");
  }

  @Test
  public void testTypeCheckFailTooFewMethodArguments() {
    testPass("TypeCheckFailTooFewMethodArguments.java");
  }

  @Test
  public void testTypeCheckFailTooManyMethodArguments() {
    testPass("TypeCheckFailTooManyMethodArguments.java");
  }

  @Test
  public void testTypeCheckFailUndefinedClass() {
    testPass("TypeCheckFailUndefinedClass.java");
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
