import Node

class basicOperator:
	def isEmptyNode(self,node):
		if node == None:
			return 1
		else:
			return 0	

	def isBiggerThanNodeValue(self,insertedValue,nodeValue):
		if insertedValue >= nodeValue:
			return 1
		else:
			return 0

class Insert(basicOperator):
	def makeNewNode(self,value):
		newNode = Node.Node(value,None,None)

		return newNode

class Delete(basicOperator):
	def isSameNum(self,targetValue,node):
		if targetValue == node.value:
			return 1
		
		else:
			return 0
		
	def checkDeleteTypeFromChilds(self,node):
		if node.rightNode == None and node.leftNode == None:
			return 0 
		
		elif node.rightNode != None and node.leftNode == None:
			return 1
		
		elif node.rightNode == None and node.leftNode != None:
			return 2

		else:
			return 3

	def moveToLastLeftNode(self,targetNode):
		self.saveCurrentPositionNode = targetNode.rightNode

		while 1:
			if self.isEmptyNode(self.saveCurrentPositionNode.leftNode) == 1:
				return self.saveCurrentPositionNode

			else:
				self.saveCurrentPositionNode = self.saveCurrentPositionNode.leftNode

	def deleteNode(self,parentNode,targetNode,deleteType):
		if deleteType == 0:
			if parentNode == None:
				return None				

			elif self.isBiggerThanNodeValue(targetNode.value,parentNode.value) == 1:
				parentNode.rightNode = None

			else:
				parentNode.leftNode = None
		elif deleteType == 1:
			if parentNode == None:
				return targetNode.rightNode

			elif self.isBiggerThanNodeValue(targetNode.value,parentNode.value) == 1:
				parentNode.rightNode = targetNode.rightNode

			else:
				parentNode.leftNode = targetNode.rightNode

		elif deleteType == 2:
			if parentNode == None:
				return targetNode.leftNode

			elif self.isBiggerThanNodeValue(targetNode.value,parentNode.value) == 1:
				parentNode.rightNode = targetNode.leftNode

			else:
				parentNode.leftNode = targetNode.leftNode

		else:
			self.saveLastLeftNode = self.moveToLastLeftNode(targetNode)
			self.saveLastLeftNode.leftNode = targetNode.leftNode

			if parentNode == None:
				return targetNode.rightNode		

			elif self.isBiggerThanNodeValue(targetNode.value,parentNode.value) == 1:
				parentNode.rightNode = targetNode.rightNode

			else:
				parentNode.leftNode = targetNode.rightNode		