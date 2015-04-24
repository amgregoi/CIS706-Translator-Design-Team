package sjc.symboltable.extended;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.eclipse.jdt.core.dom.ASTNode;
import org.eclipse.jdt.core.dom.ArrayCreation;
import org.eclipse.jdt.core.dom.ClassInstanceCreation;
import org.eclipse.jdt.core.dom.CompilationUnit;
import org.eclipse.jdt.core.dom.FieldAccess;
import org.eclipse.jdt.core.dom.FieldDeclaration;
import org.eclipse.jdt.core.dom.Modifier;
import org.eclipse.jdt.core.dom.Modifier.ModifierKeyword;
import org.eclipse.jdt.core.dom.TypeDeclaration;
import org.eclipse.jdt.core.dom.VariableDeclarationFragment;

import sjc.annotation.NonNull;
import sjc.annotation.NonNullElements;
import sjc.symboltable.SymbolTableBuilder;
import sjc.util.Pair;

/**
 * This class is used to build symbol table for an ExtendedStaticJava
 * {@link CompilationUnit}. Note that the algorithm assumes that the JDT AST
 * tree was built using the {@link sjc.parser.extended.ASTParser}. That is, it
 * assumes certain structures on the AST, e.g., a class does not have an
 * instance method.
 * 
 * @author <a href="mailto:robby@cis.ksu.edu">Robby</a>
 */
public class ExtendedSymbolTableBuilder extends SymbolTableBuilder {
  /**
   * The visitor for {@link ASTNode} to resolve symbols.
   * 
   * @author <a href="mailto:robby@cis.ksu.edu">Robby</a>
   */
  protected static class Visitor extends SymbolTableBuilder.Visitor {
    protected @NonNullElements
    Map<String, TypeDeclaration> classMap = new HashMap<String, TypeDeclaration>();

    protected @NonNullElements
    Map<Pair<String, String>, FieldDeclaration> fieldMap = new HashMap<Pair<String, String>, FieldDeclaration>();

    /**
     * Unlink references and clear maps/collections.
     */
    @Override
    protected void dispose() {
      super.dispose();
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

    @Override
    public boolean visit(final ArrayCreation node) {
      // Note that we don't visit the ArrayCreation's type
      // because we want visit(SimpleName) to resolve variable references
      // instead of method names.
      for (final Object o : node.dimensions()) {
        ((ASTNode) o).accept(this);
      }
      if (node.getInitializer() != null) {
        node.getInitializer().accept(this);
      }
      return false;
    }

    @Override
    public boolean visit(final ClassInstanceCreation node) {
      // Note that we don't visit the ClassInstanceCreation's name
      // because we want visit(SimpleName) to resolve variable references
      // instead of method names.
      return false;
    }

    @Override
    public boolean visit(final FieldAccess node) {
      // Note that we don't visit the FieldAccess's name
      // because we want visit(SimpleName) to resolve variable references
      // instead of method names.
      node.getExpression().accept(this);
      return false;
    }

    @Override
    public boolean visit(final TypeDeclaration node) {
      if (hasPublicModifier(node.modifiers())) { // use super's visit method because this node is the main class
        return super.visit(node);
      }

      final String className = node.getName().getIdentifier();
      if (this.classMap.containsKey(className)) {
        throw new Error(node, "Error in class declaration '" + className
            + "' : the class name has been used in:\n"
            + this.classMap.get(className));
      }
      this.classMap.put(className, node);

      for (final Object o : node.bodyDeclarations()) {
        // simple class declaration only has field declarations
        final FieldDeclaration fd = (FieldDeclaration) o;

        final VariableDeclarationFragment vdf = (VariableDeclarationFragment) fd
            .fragments().get(0);
        final String name = vdf.getName().getIdentifier();
        final Pair<String, String> p = new Pair<String, String>(className, name);
        if (this.fieldMap.containsKey(p)) {
          throw new Error(fd, "Error in field declaration '" + name
              + "' : the field name has been used in:\n"
              + this.fieldMap.get(name));
        }
        this.fieldMap.put(p, fd);
      }
      return false;
    }
  }

  /**
   * Builds a {@link ExtendedSymbolTable} for the given ExtendedStaticJava
   * {@link CompilationUnit}.
   * 
   * @param cu
   *          The {@link CompilationUnit}.
   * @return The {@link ExtendedSymbolTable} for the given
   *         {@link CompilationUnit}.
   * @throws SymbolTableBuilder.Error
   *           If the builder encounter unresolvable symbol.
   */
  public static @NonNull
  ExtendedSymbolTable build(@NonNull final CompilationUnit cu)
      throws SymbolTableBuilder.Error {
    assert cu != null;

    final Visitor v = new Visitor();
    cu.accept(v);
    final ExtendedSymbolTable result = new ExtendedSymbolTable(v.result,
        v.classMap, v.fieldMap);
    v.dispose();
    return result;
  }

  /**
   * Declared as protected to disallow creation of this object outside from the
   * methods of this class.
   */
  protected ExtendedSymbolTableBuilder() {
    super();
  }
}
