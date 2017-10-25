import BSToperator
import Print

class BST:
	headerNode = None
	currentPositionNode = None
	parentNode = None
	callInsert = None
	callDelete = None
	callPrint = None

	def __init__(self):
		BST.callInsert = BSToperator.Insert()
		BST.callDelete = BSToperator.Delete()

	def insert(self,value):
		BST.currentPositionNode = BST.headerNode

		while 1:
			if BST.callInsert.isEmptyNode(BST.headerNode) == 1:
				BST.headerNode = BST.callInsert.makeNewNode(value)
				BST.currentPositionNode = BST.headerNode

				break
			
			else:
				if BST.callInsert.isBiggerThanNodeValue(value,BST.currentPositionNode.value) == 1:
					if BST.callInsert.isEmptyNode(BST.currentPositionNode.rightNode) == 1:
						BST.currentPositionNode.rightNode = BST.callInsert.makeNewNode(value)
						break
					else:
						BST.currentPositionNode = BST.currentPositionNode.rightNode

				else:
					if BST.callInsert.isEmptyNode(BST.currentPositionNode.leftNode) == 1:
						BST.currentPositionNode.leftNode = BST.callInsert.makeNewNode(value)
						break
					else:
						BST.currentPositionNode = BST.currentPositionNode.leftNode
		
	def delete(self,value):
		BST.currentPositionNode = BST.headerNode

		while 1:
			if BST.callDelete.isEmptyNode(BST.currentPositionNode) == 1:
				print("Delete Failed : Value cannot be fined")
				break
	
			elif BST.callDelete.isSameNum(value,BST.currentPositionNode) == 1:
				if BST.parentNode == None:
					BST.headerNode = BST.callDelete.deleteNode(BST.parentNode,BST.currentPositionNode,
							BST.callDelete.checkDeleteTypeFromChilds(BST.currentPositionNode))

				else:
					BST.callDelete.deleteNode(BST.parentNode,BST.currentPositionNode,
							BST.callDelete.checkDeleteTypeFromChilds(BST.currentPositionNode))

				break
				
			else:
				if BST.callDelete.isBiggerThanNodeValue(value,BST.currentPositionNode.value) == 1:
					BST.parentNode = BST.currentPositionNode
					BST.currentPositionNode = BST.currentPositionNode.rightNode

				else:
					BST.parentNode = BST.currentPositionNode
					BST.currentPositionNode = BST.currentPositionNode.leftNode

	def print_preorder(self):
		BST.callPrint = Print.Preorder()
		BST.callPrint.startPreorder(BST.headerNode)
				
	def print_inorder(self):
		BST.callPrint = Print.Inorder()
		BST.callPrint.startInorder(BST.headerNode)

	def print_postorder(self):
		BST.callPrint = Print.Postorder()
		BST.callPrint.startPostorder(BST.headerNode)
			