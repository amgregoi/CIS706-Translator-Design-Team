package sjc.symboltable.extended;

import java.util.Map;
import java.util.TreeSet;

import org.eclipse.jdt.core.dom.ASTNode;
import org.eclipse.jdt.core.dom.ArrayCreation;
import org.eclipse.jdt.core.dom.ClassInstanceCreation;
import org.eclipse.jdt.core.dom.CompilationUnit;
import org.eclipse.jdt.core.dom.FieldAccess;
import org.eclipse.jdt.core.dom.FieldDeclaration;
import org.eclipse.jdt.core.dom.TypeDeclaration;

import sjc.annotation.NonNull;
import sjc.annotation.NonNullElements;
import sjc.annotation.ReadOnlyElements;
import sjc.symboltable.SymbolTable;
import sjc.util.Pair;
import sjc.util.Util;

/**
 * This class represents a symbol table for an ExtendedStaticJava
 * {@link CompilationUnit}. The {@link symbolMap} is augmented with mappings of
 * {@link FieldAccess} to its {@link FieldDeclaration},
 * {@link ClassInstanceCreation} to its {@link TypeDeclaration}, Note that
 * {@link FieldAccess}, {@link ArrayCreation}, and {@link ClassInstanceCreation}
 * will be resolved in the type checking phase.
 * 
 * @author <a href="mailto:robby@cis.ksu.edu">Robby</a>
 */
public class ExtendedSymbolTable extends SymbolTable {
  /**
   * Holds the map of class fully-qualified names to their
   * {@link TypeDeclaration}.
   */
  public final @NonNullElements
  @ReadOnlyElements
  Map<String, TypeDeclaration> classMap;

  /**
   * Holds the map of pairs of class fully-qualified and field names to their
   * {@link FieldDeclaration}.
   */
  public final @NonNullElements
  @ReadOnlyElements
  Map<Pair<String, String>, FieldDeclaration> fieldMap;

  /**
   * Constructs a symbol table for an ExtendedStaticJava {@link CompilationUnit}
   * .
   * 
   * @param symbolMap
   *          The symbol map.
   * @param classMap
   *          The class map.
   * @param fieldMap
   *          The field map.
   */
  public ExtendedSymbolTable(
      @NonNullElements final Map<ASTNode, Object> symbolMap,
      @NonNullElements final Map<String, TypeDeclaration> classMap,
      @NonNullElements final Map<Pair<String, String>, FieldDeclaration> fieldMap) {
    super(symbolMap);
    assert Util.checkNonNullElements(classMap)
        && Util.checkNonNullElements(fieldMap);
    this.classMap = classMap;
    this.fieldMap = fieldMap;
  }

  /**
   * Returns the {@link String} representation of this extended symbol table.
   * 
   * @return The {@link String} representation of this extended symbol table.
   */
  @Override
  public @NonNull
  String toString() {
    final String lineSep = System.getProperty("line.separator");
    final StringBuilder sb = new StringBuilder();
    final TreeSet<String> set = new TreeSet<String>();
    for (final String s : this.classMap.keySet()) {
      set.add(s + " ==> " + Util.getFirstLine(this.classMap.get(s)));
    }
    for (final String s : set) {
      sb.append(s);
      sb.append(lineSep);
    }
    set.clear();
    for (final String s : set) {
      sb.append(s);
      sb.append(lineSep);
    }
    for (final Pair<String, String> p : this.fieldMap.keySet()) {
      set.add(p.first + "." + p.second + " ==> "
          + Util.getFirstLine(this.fieldMap.get(p)));
    }
    sb.append(super.toString());
    return sb.toString();
  }
}
