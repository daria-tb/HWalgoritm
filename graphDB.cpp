#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cassert>

/*
ЗАВДАННЯ 1:
Реалізація графа з методами обходу:
- DFS (пошук в глибину)
- BFS (пошук в ширину)

Ми використовуємо масив visited для позначення вершин, які вже були відвідані під час обходу.
Це сигналізує про те, що до цієї вершини ми вже приходили, і дозволяє уникнути зациклення.

ЗАВДАННЯ 2:
Пояснення:
- У DFS `visited` передається як аргумент, тому що це рекурсивний алгоритм. Щоб усі виклики DFS мали спільний доступ до масиву відвіданих вершин, він передається по посиланню.
- У BFS `visited` створюється всередині функції, бо алгоритм ітеративний, і ми не потребуємо рекурсивного поширення стану.
*/

class Graph
{
private:
	void DFS(int v, std::vector<bool>& visited) const;

public:
	Graph(size_t V);

	void addEdge(size_t u, size_t v);
	size_t getNumVertices() const;
	void print() const;

	void DFSFrom(size_t startVertex) const;
	void DFSAll() const;

	void BFSFrom(size_t startVertex) const;
	void BFSAll() const;

private:
	size_t _V; // Кількість вершин у графі
	std::vector<std::set<int>> _adj; // Список суміжності (набір сусідів для кожної вершини)
};

Graph::Graph(size_t V) : _V(V)
{
	_adj.resize(V);
}

// Додає ребро між вершинами u і v
void Graph::addEdge(size_t u, size_t v)
{
	assert(u < _V && v < _V);
	_adj[u].insert(v);
	_adj[v].insert(u); // Неорієнтований граф
}

size_t Graph::getNumVertices() const
{
	return _V;
}

// Виводить список суміжності для кожної вершини
void Graph::print() const
{
	for (int i = 0; i < _V; i++)
	{
		std::cout << "Vertex " << i << " is connected with: ";
		for (auto neighbor : _adj[i])
		{
			std::cout << neighbor << " ";
		}
		std::cout << '\n';
	}
}

// Рекурсивна функція DFS — обходить граф починаючи з вершини v
void Graph::DFS(int v, std::vector<bool>& visited) const
{
	visited[v] = true; // Позначаємо вершину як відвідану
	std::cout << "Visited (DFS): " << v << std::endl;

	for (auto neighbor : _adj[v]) // Обходимо сусідів
	{
		if (!visited[neighbor]) // Якщо ще не були там — йдемо глибше
		{
			DFS(neighbor, visited);
		}
	}
}

// Запуск DFS з конкретної вершини
void Graph::DFSFrom(size_t startVertex) const
{
	assert(startVertex < _V);
	std::vector<bool> visited(_V, false); // Масив відвіданих вершин
	DFS(startVertex, visited);
}

// Запуск DFS з кожної непровідваної вершини (на випадок, якщо граф не зв’язний)
void Graph::DFSAll() const
{
	std::vector<bool> visited(_V, false);
	for (size_t i = 0; i < _V; ++i)
	{
		if (!visited[i])
		{
			DFS(i, visited);
		}
	}
}

// Обхід в ширину з заданої вершини
void Graph::BFSFrom(size_t startVertex) const
{
	assert(startVertex < _V);
	std::vector<bool> visited(_V, false); // Локальний масив відвіданих вершин
	std::queue<size_t> q;

	visited[startVertex] = true;
	q.push(startVertex);

	while (!q.empty())
	{
		size_t v = q.front();
		q.pop();

		std::cout << "Visited (BFS): " << v << std::endl;

		for (auto neighbor : _adj[v])
		{
			if (!visited[neighbor])
			{
				visited[neighbor] = true;
				q.push(neighbor);
			}
		}
	}
}

// BFS обхід для всього графа (якщо не зв’язний)
void Graph::BFSAll() const
{
	std::vector<bool> visited(_V, false);

	for (size_t i = 0; i < _V; ++i)
	{
		if (!visited[i])
		{
			std::queue<size_t> q;
			visited[i] = true;
			q.push(i);

			while (!q.empty())
			{
				size_t v = q.front();
				q.pop();

				std::cout << "Visited (BFS): " << v << std::endl;

				for (auto neighbor : _adj[v])
				{
					if (!visited[neighbor])
					{
						visited[neighbor] = true;
						q.push(neighbor);
					}
				}
			}
		}
	}
}

// Головна функція: створюємо граф, додаємо ребра, виводимо структуру та запускаємо обходи
int main()
{
	Graph g(6);

	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 4);
	g.addEdge(4, 5);

	std::cout << "Graph structure:\n";
	g.print();

	std::cout << "\nDepth-First Search:\n";
	g.DFSAll();

	std::cout << "\nBreadth-First Search:\n";
	g.BFSAll();

	return 0;
}
