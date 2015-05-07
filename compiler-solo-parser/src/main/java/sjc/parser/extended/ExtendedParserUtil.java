package sjc.parser.extended;

import java.io.FileReader;

import org.antlr.v4.runtime.ANTLRInputStream;
import org.antlr.v4.runtime.BaseErrorListener;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.RecognitionException;
import org.antlr.v4.runtime.Recognizer;

import sjc.parser.extended.ExtendedStaticJavaParser.CompilationUnitContext;

public class ExtendedParserUtil {

  public static CompilationUnitContext parse(final String path)
      throws Exception {
    final ANTLRInputStream input = new ANTLRInputStream(new FileReader(path));
    final ExtendedStaticJavaLexer lexer = new ExtendedStaticJavaLexer(input);
    final CommonTokenStream tokens = new CommonTokenStream(lexer);
    final ExtendedStaticJavaParser parser = new ExtendedStaticJavaParser(tokens);
    parser.removeErrorListeners();
    parser.addErrorListener(new BaseErrorListener() {
      @Override
      public void syntaxError(final Recognizer<?, ?> recognizer,
          final Object offendingSymbol, final int line,
          final int charPositionInLine, final String msg,
          final RecognitionException e) {
        throw new RuntimeException("Parse Error in " + path + ": [" + line
            + ", " + charPositionInLine + "] " + msg);
      }
    });
    return parser.compilationUnit();
  }
}
