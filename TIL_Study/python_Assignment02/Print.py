import Node

class Preorder:
	def startPreorder(self,currentPositionNode):
		if currentPositionNode == None:
			return

		else:
			print(currentPositionNode.value)

			self.startPreorder(currentPositionNode.leftNode)
			self.startPreorder(currentPositionNode.rightNode)

class Inorder:
	def startInorder(self,currentPositionNode):
		if currentPositionNode == None:
			return

		else:
			self.startInorder(currentPositionNode.leftNode)

			print(currentPositionNode.value)

			self.startInorder(currentPositionNode.rightNode)

class Postorder:
	def startPostorder(self,currentPositionNode):
		if(currentPositionNode == None):
			return

		else:
			self.startPostorder(currentPositionNode.leftNode)
			self.startPostorder(currentPositionNode.rightNode)

			print(currentPositionNode.value)
		