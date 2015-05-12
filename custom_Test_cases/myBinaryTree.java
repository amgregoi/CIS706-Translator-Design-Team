class Tree{
	public TreeNode root;
}

class TreeNode{
	public int value;
	public TreeNode leftChild;
	public TreeNode rightChild;
}

public class BinaryTree {

	public static void main(String[] args) {
		Tree testTree;
		
		testTree = btNewTree();

		btAddNode(testTree, 5);
		btAddNode(testTree, 3);
		btAddNode(testTree, 7);
		btAddNode(testTree, 10);
		btAddNode(testTree, 2);
		btAddNode(testTree, 4);
		btAddNode(testTree, 6);
		
		StaticJavaLib.assertTrue(btCheckSum(testTree.root, 1) == 91);
	}
	
	static Tree btNewTree()
	{
		return new Tree();
	}
	
	static TreeNode btNewNode(int value, TreeNode left, TreeNode right)
	{
		TreeNode newNode;
		newNode = new TreeNode();
		newNode.value = value;
		newNode.leftChild = left;
		newNode.rightChild = right;
		
		return newNode;
	}
	
	static void btAddNode(Tree tree, int value)
	{
		boolean addedValue;
		TreeNode currentNode;
		TreeNode nodeToAdd;
		
		addedValue = false;
		currentNode = tree.root;
		
		nodeToAdd = btNewNode(value, null, null);
		
		if(currentNode == null)
		{
			tree.root = nodeToAdd;
			return;
		}
		
		while(!addedValue)
		{
			if(currentNode.value < value)
			{
				if(currentNode.rightChild == null)
				{
					currentNode.rightChild = nodeToAdd;
					addedValue = true;
					return;
				}
				else
				{
					currentNode = currentNode.rightChild;
				}
			}
			else {
				if (currentNode.value >= value){
					if(currentNode.leftChild == null)
					{
						currentNode.leftChild = nodeToAdd;
						addedValue = true;
						return;
					}
					else
					{
						currentNode = currentNode.leftChild;
					}
				}
			}
		}
	}
	
	static void btAddTreeNode(Tree tree, TreeNode newNode)
	{
		TreeNode currentNode;
		
		if(tree.root == null)
		{
			tree.root = newNode;
			return;
		}
		
		currentNode = tree.root;
		
		while(currentNode != null)
		{
			if(currentNode.value >= newNode.value)
			{
				if(currentNode.rightChild == null)
				{
					currentNode.rightChild = newNode;
					return;
				}
				else
				{
					currentNode = currentNode.rightChild;
				}
			}
			else {
				if(currentNode.value < newNode.value)
				{
					if(currentNode.leftChild == null)
					{
						currentNode.leftChild = newNode;
						return;
					}
					else
					{
						currentNode = currentNode.leftChild;
					}
				}
			}
		}
	}
	
	static int btCheckSum(TreeNode treeNode, int multiplier)
	{
		int returnValue;
		int leftValue;
		int rightValue;
		
		if(treeNode == null){
			return 0;
		}
		
		returnValue = multiplier * treeNode.value;
		multiplier++;
		
		leftValue = btCheckSum(treeNode.leftChild, multiplier);
		
		rightValue = btCheckSum(treeNode.rightChild, multiplier);
		
		return returnValue + leftValue + rightValue;
	}

}
