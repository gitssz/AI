
# Number of vertices in the graph
# define 4 4

# check if the colored graph is safe or not
def isSafe(graph, color):

# comparing the colors of adjacent vertices 
	for i in range(4):
		for j in range(i + 1, 4):
			if (graph[i][j] and color[j] == color[i]):   
				return False   #if andjacent vertice have same color return false
	return True

def graphColoring(graph, m, i, color):
#m= number of colors for coloring
#i= index of current vertex being considered

	#if current index reached end
	if (i == 4):

		# if coloring the last index is safe
		if (isSafe(graph, color)):
			#Print the solution
			printSolution(color)
			return True
		return False

	#Trying to assign each color from 1 to m
	for j in range(1, m + 1):
		color[i] = j

		# Recurive call to graphColring for the next vertex(i+1)
		if (graphColoring(graph, m, i + 1, color)):
			return True
		color[i] = 0 #else, reset color for current vertex n start coloring again
	return False


def printSolution(color):
	print("Solution Exists:" " Following are the assigned colors ")
	for i in range(4):
		print(color[i], end=" ")


if __name__ == '__main__':

	#adjacency matrix
	graph = [
		[0, 1, 1, 1],
		[1, 0, 1, 0],
		[1, 1, 0, 1],
		[1, 0, 1, 0],
	]
	m = 3 #Number of colors

	color = [0 for i in range(4)] #array stores the assigned colors for each vertex

	# Function call
	if (not graphColoring(graph, m, 0, color)):
		print("Solution does not exist")
