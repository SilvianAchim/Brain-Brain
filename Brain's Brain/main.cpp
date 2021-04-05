//Brain's Brain made by Silvian Achim
// Youtube: https://www.youtube.com/c/SilvianAchim
#include <SFML/Graphics.hpp>

#define WIDTH 384
#define HEIGHT 216
#define CELLS 40000

using namespace sf;

int board1[HEIGHT + 1][WIDTH + 1];
int board2[HEIGHT + 1][WIDTH + 1];
int size = 5, first = 1, board = 1;

void cellInitialization()
{
	for (int i = 1; i <= CELLS; i++)
	{
		int x = rand() % WIDTH + 1;
		int y = rand() % HEIGHT + 1;
		board1[y][x] = 2;
	}
}

void gen1(int i, int j)
{
	if (board1[i][j] == 2) // alive
	{
		board2[i][j] = 1;
	}
	else if (board1[i][j] == 1) // dying
	{
		board2[i][j] = 0;
	}
	else if (board1[i][j] == 0) // dead
	{
		int neighbors = 0;
		if (board1[i - 1][j - 1] == 2)
		{
			neighbors++;
		}
		if (board1[i - 1][j] == 2)
		{
			neighbors++;
		}
		if (board1[i - 1][j + 1] == 2)
		{
			neighbors++;
		}
		if (board1[i][j - 1] == 2)
		{
			neighbors++;
		}
		if (board1[i][j + 1] == 2)
		{
			neighbors++;
		}
		if (board1[i + 1][j - 1] == 2)
		{
			neighbors++;
		}
		if (board1[i + 1][j] == 2)
		{
			neighbors++;
		}
		if (board1[i + 1][j + 1] == 2)
		{
			neighbors++;
		}
		if (neighbors == 2)
		{
			board2[i][j] = 2;
		}

	}
}

void gen2(int i, int j)
{
	if (board2[i][j] == 2) // alive
	{
		board1[i][j] = 1;
	}
	else if (board2[i][j] == 1) // dying
	{
		board1[i][j] = 0;
	}
	else if (board2[i][j] == 0) // dead
	{
		int neighbors = 0;
		if (board2[i - 1][j - 1] == 2)
		{
			neighbors++;
		}
		if (board2[i - 1][j] == 2)
		{
			neighbors++;
		}
		if (board2[i - 1][j + 1] == 2)
		{
			neighbors++;
		}
		if (board2[i][j - 1] == 2)
		{
			neighbors++;
		}
		if (board2[i][j + 1] == 2)
		{
			neighbors++;
		}
		if (board2[i + 1][j - 1] == 2)
		{
			neighbors++;
		}
		if (board2[i + 1][j] == 2)
		{
			neighbors++;
		}
		if (board2[i + 1][j + 1] == 2)
		{
			neighbors++;
		}
		if (neighbors == 2)
		{
			board1[i][j] = 2;
		}
	}
}

int main()
{
	RenderWindow window(VideoMode(1920, 1080), "Brain's Brain made by Silvian Achim", Style::Fullscreen);
	window.setFramerateLimit(60);
	Texture t1, t2;
	t1.loadFromFile("Blue5.png");
	t2.loadFromFile("Gray5.png");
	Sprite B(t1);
	Sprite G(t2);

	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				window.close();
			}
		}
		if (first == 1)
		{
			cellInitialization();
			first = 0;
		}
		window.clear(Color::Black);
		for (int i = 1; i <= HEIGHT; i++)
		{
			for (int j = 1; j <= WIDTH; j++)
			{
				if (board == 1)
				{
					gen1(i, j);
				}
				else if (board == 2)
				{
					gen2(i, j);
				}
			}
		}
		if (board == 1)
		{
			board = 2;
			for (int i = 1; i <= HEIGHT; i++)
			{
				for (int j = 1; j <= WIDTH; j++)
				{
					board1[i][j] = 0;
				}
			}
		}
		else if (board == 2)
		{
			board = 1;
			for (int i = 1; i <= HEIGHT; i++)
			{
				for (int j = 1; j <= WIDTH; j++)
				{
					board2[i][j] = 0;
				}
			}
		}
		if (board == 1)
		{
			for (int i = 1; i <= HEIGHT; i++)
			{
				for (int j = 1; j <= WIDTH; j++)
				{
					if (board1[i][j] == 2)
					{
						B.setPosition(j * size, i * size);
						window.draw(B);
					}
					if (board1[i][j] == 1)
					{
						G.setPosition(j * size, i * size);
						window.draw(G);
					}
				}
			}
		}
		else if (board == 2)
		{
			for (int i = 1; i <= HEIGHT; i++)
			{
				for (int j = 1; j <= WIDTH; j++)
				{
					if (board2[i][j] == 2)
					{
						B.setPosition(j * size, i * size);
						window.draw(B);
					}
					if (board1[i][j] == 1)
					{
						G.setPosition(j * size, i * size);
						window.draw(G);
					}
				}
			}
		}
		window.display();
	}
}