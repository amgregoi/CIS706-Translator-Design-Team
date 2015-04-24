package sjc.ast.extended;

import org.eclipse.jdt.core.dom.CompilationUnit;

import sjc.parser.extended.ExtendedParserUtil;

public class ExtendedASTUtil {
  public static CompilationUnit ast(final String filename) throws Exception {
    return ExtendedStaticJavaASTBuilder.ast(ExtendedParserUtil.parse(filename));
  }
}
