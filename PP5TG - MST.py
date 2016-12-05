class Vertex:
	def __init__(self, k, p, i):
		self.key = k
		self.pi = p
		self.index = i
	
	def __lt__(self,other):
		if(self.key < other.key):
			return True
		else:
			return False
	def print(self):
		print("(",self.key, ", ", self.pi, ", ", self.index,")", end =' ')

def extractMin(Q):
	Q = sorted(Q)
	return Q.pop(0)

def inList(Q, adj):
	for i in range (len(Q)):
		if (Q[i].index == adj):
			return True
	return False
def prim(G, r):
	Q = []
	for i in range (len(graph)):
		k = float("inf")
		p = None
		u = Vertex(k, p, i)
		if (i == 0):
			u.key = 0
		Q.append(u)
	aux = Q.copy()
	weights = []
	while (len(Q) > 0):
		Q.sort()
		print(len(Q))
		for i in range(len(Q)):
			Q[i].print()
		print()
		u = Q.pop(0)
		print("u atualmente vale: ", u.index)
		for i in range(0,len(G[u.index])):
			adj = G[u.index][i][0]
			if (inList(Q, adj) and (G[u.index][i][1] < aux[adj].key)):
				#pi2 = u
				#key2 = G[u.index][1]
				#t = Vertex(adj, pi2, key2)
				aux[adj].key = G[u.index][i][1]
	print()
	print("VETOR AUXILIAR: ")
	for i in range (len(aux)):
		aux[i].print()
	return aux
		
countVertices = int(input ())

graph = {}

for i in range ( countVertices ):
	inputToList = [ int(x) for x in input (). split (" ")]
	adjacents = []
	for j in range (len(inputToList)):
		if inputToList [j] != 0:
			edge = j, inputToList[j]
			adjacents.append(edge)
	graph [i] = adjacents
#print(graph[0])
MST = prim(graph, 0)
sumWeights = 0
for i in range(len(MST)):
	sumWeights+=MST[i].key
print(sumWeights)