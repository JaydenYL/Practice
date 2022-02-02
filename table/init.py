#!/usr/bin/env python3
global num_path
num_path = 0

class Path:
	
	def __init__(self, start, end):
		self.passed_by = False
		self.start = start
		self.end = end
		
		
	def __str__(self):
		return "{}-{} [{}]".format(self.start, self.end, "T" if self.passed_by else "F")


class Node:
	
	def __init__(self, x, y):
		self.x = x
		self.y = y
		self.edges = []


	def add_path(self, n):
		global num_path
		for edge in self.edges:
			if edge.end == n:
#				print("edges ({}, {}) has already been added".format(n.x, n.y))
				return False  # The edges has been alreadly added
		self.edges.append(Path(self, n))
#		print("{} --- {}".format(self, n))
		num_path += 1
		
#		n.add_path(self)
		return True  # Successfully added the new edge
	
	def get_path(self, n):
		for edge in self.edges:
			if edge.end == n:
				return edge
		return None
	
	
	def __str__(self):
		return "({}, {})".format(self.x, self.y)
	
	
	def __eq__(self, other):
		return (self.x == other.x) and (self.y == other.y)



class Map:
	
	def __init__(self, N):
		self.N = N
		self.num_path = 0
		self.matrix = []
		for i in range(0, N):
			self.matrix.append([])

		i = 0
		while i < N:
			j = 0
			while j < N:
				self.matrix[i].append(Node(i, j))
				j += 1
			i += 1
		
		
	def process_data(self, adjacent_ls):
		i = 0
		while i < self.N:
			j = 0
			while j < self.N:
				cur_node = self.matrix[i][j]
				edge_ls = adjacent_ls[i][j]
				for coord in edge_ls:
					cur_node.add_path(self.matrix[coord[0]][coord[1]])
				j += 1
			i += 1
		

	
class Solution:
	
	def __init__(self, N):
		ls_adjacent = []
		
		self.N = N
		for i in range(0, N):
			ls_adjacent.append([])
			
		self.solution = []
		self.map = Map(N)
		
		

	def dfs(self, pre_node: Node, cur_node: Node):
		self.solution.append(cur_node)

		if len(self.solution) - 1 == num_path:
			return True
		
#		print(", ".join(str(ele) for ele in cur_node.edges))
#		print(cur_node.edges)
		for path in cur_node.edges:
			if not path.passed_by:
				path.passed_by = True
#				print(cur_node)
#				print(path.end)
				path.end.get_path(cur_node).passed_by = True
				res = self.dfs(cur_node, path.end)
				if res:
					return True
			else:
				continue
		
		deleted = self.solution.pop()
#		print(deleted)
		if pre_node:
			cur_node.get_path(pre_node).passed_by = False
			passed_path = pre_node.get_path(cur_node)
			if passed_path:
				passed_path.passedby = False
			else:
				print("Miss path")
		
		return False
			
	
	

N = 5

#ls = [
#	[[(1, 0), (1, 1), (0, 1)],  		[(0, 0), (1, 1), (2, 1), (0,2)], 				[(0,1), (1,2), (2,2), (2,1)]],
#	[[(0, 0), (1, 1), (2, 0)], 		[(0,0), (1,0), (2,0), (2, 2), (1, 2), (0, 1)], 	[(1,1), (0,2)]],
#	[[(1,0), (1,1), (2,1), (2,2)],	[(0,1), (0,2),(2,0), (2,2)],					[(1,1), (2,0), (2,1), (0,2)]]
#]
#
#
#ls_2 = [
#	[[(1,0)],			[(1,1), (0,2)],	[(0,1), (1,2)]],
#	[[(0,0), (2,0)], 	[(0,1)], 		[(0,2), (2,2)]],
#	[[(1,0), (2,1)], 	[(2,0), (2,2)], [(2,1), (1,2)]]
#]

ls_3 = [
	[[(0,1), (1,1), (2,2), (2,0)], [(0,0), (1,1), (0, 2), (3,2)], [(1,1), (0,1)], [(0,4), (1,3), (1,2), (2,1)], [(1,4), (2,4), (3,3), (2,3), (2,0), (0,3)]],
	[[], [(0,0), (0,1), (0,2), (1,3), (4,0), (2,0)], [(0,3), (1,3), (2,1), (2,0)], [(1,1), (0,3), (1,4), (3,4), (3,3), (2,2), (1,2)], [(0,4), (1,3)]],
	[[(0,0), (1,1), (1,2), (0,4), (2,1), (4,2), (4,0)], [(1,2), (0,3), (2,2), (3,2), (3,1), (4,0), (3,0), (2,0)], [(1,3), (2,3), (3,3), (3,2), (2,1), (0, 0)], [(0,4), (2,4), (3,3), (2,2)], [(0,4), (3,4), (4,4), (4,2), (3,2), (2,3)]],
	[[(2,1), (3,2), (4,3), (4,0)], [(2,1), (4,1)], [(2,2), (2,4), (3,3), (4,3), (4,0), (3,0), (2,1), (0,1)], [(2,3), (1,3), (0,4), (4,3), (3,2), (2,2)], [(2,4), (4,4), (4,3), (1,3)]],
	[[(3,0), (2,0), (3,2), (4,2), (2,1), (1,1)], [(3,1), (4,2)], [(2,4), (4,3), (4,4), (4,1), (4,0), (2,0)], [(3,3), (3,4), (4,4), (4,2), (3,0), (3,2)], [(3,4), (2,4), (4,3), (4,2)]]
]



sol = Solution(N)
sol.map.process_data(ls_3)
num_path //= 2

print(num_path)

res = sol.dfs(None, sol.map.matrix[2][0])

print(res)

print(len(sol.solution))
print("->".join(str(ele) for ele in sol.solution))
print(num_path)

