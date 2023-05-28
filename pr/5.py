#prims
INF = 9999999
V = 5

#adjacency matrix to represent graph
G = [[0, 9, 75, 0, 0],
     [9, 0, 95, 19, 42],
     [75, 95, 0, 51, 66],
     [0, 19, 51, 0, 31],
     [0, 42, 66, 31, 0]]
# create a array to track selected vertex of mst
selected = [0, 0, 0, 0, 0]
# set number of edge to 0,used to keep track of the number of edges in the MST.
nedge = 0
# choose 0th vertex and make it true
selected[0] = True
# print for edge and weight
print("Edge : Weight\n")
while (nedge < V - 1):
    minimum = INF
    #x n y store the indices of the vertices that form the minimum weight edge.
    x = 0
    y = 0
    for i in range(V):
        if selected[i]:    
            for j in range(V):
                #if that vertex is not selected n G[i][j] is non zero ie there is an edge betw i n j
                if ((not selected[j]) and G[i][j]):  
                     # not in selected and there is an edge
                    if minimum > G[i][j]:
                        minimum = G[i][j]
                        x = i   #updated with new valuses
                        y = j
    #printing selected edge x-y and its weight G[x][y]
    print(str(x) + "-" + str(y) + ":" + str(G[x][y]))
    selected[y] = True
    nedge += 1 #a new edge has been selected in mst