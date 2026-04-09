import os

def create_graph(adj, num_vertices):
    for i in range(num_vertices):
        #asks the user for the degree (number of neighbors) of the current vertex
        n = int(input(f'Enter the number of neighbors of {i}: '))
        neighbors = []

        for j in range(n):
            #collects each neighbor and adds them to an adjacency list
            val = int(input(f'Enter the neighbor {j} of {i}: '))
            neighbors.append(val) #adjacency list

        adj[i] = neighbors 

def display_graph(adj, num_vertices):
    for i in range(num_vertices):
        current_neighbors = adj[i]
        print(f'The neigbors of node {i} are: ', end="")
        
        for neighbor in range(len(current_neighbors)):
            neighbor = current_neighbors[neighbor]
            print(f'\t{neighbor}', end="")
        print()

def delete_graph(adj, num_vertices):
    for i in range(num_vertices):
        #leaves an empty list
        adj[i].clear()

def generate_mermaid(adj, num_vertices):
    print('\n\nMermaid Diagram')
    print()
    mermaid_lines = ['graph TD']

    for i in range(num_vertices):
        for neighbor in adj[i]:
            mermaid_lines.append(f'    {i} --> {neighbor}') 
    
    #join w newlines
    mermaid_code = '\n'.join(mermaid_lines)

    #taken from documentation and manipulated to fit this project
    html = f"<html><head><script src='https://cdn.jsdelivr.net/npm/mermaid@10/dist/mermaid.min.js'></script></head><body><div class='mermaid'>{mermaid_code}</div></body></html>"

    with open('graph.html', 'w') as f:
        f.write(html)

    os.system('open graph.html')


def main():
    num_vertices = int(input('Enter the number of nodes in G: ')) #gets the number of verticies from the user

    # creates adjacency list ( a list of empty list that correlate to the number of vertices defined)
    adj = [] 
    for i in range(num_vertices):
        empty_list = []
        adj.append(empty_list)
    
    #builds the graph
    create_graph(adj, num_vertices)

    print('The graph is: ')
    display_graph(adj, num_vertices) # displays 

    generate_mermaid(adj, num_vertices)

    delete_graph(adj, num_vertices) # clean up

if __name__ == '__main__':
    main()