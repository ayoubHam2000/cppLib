#include <iostream>
#include "LibX.hpp"
#include "Vector2d.hpp"

struct Player
{
	Vector2d	pos;
	Vector2d	dir;
};


Player	p;

void	game(LibX *libX)
{
	libX->putPixel(p.pos.getX(), p.pos.getY(), 0xffffff);
	p.pos = p.pos + p.dir;
	p.dir.rotate(0.01);
}

int	start(void *ptr)
{
	static int	frame;

	LibX	*libX = (LibX *)ptr;
	libX->createImage(WIDTH, HEIGHT);
	

	game(libX);
	

	libX->flushImage(0, 0);
	
	frame++;
	system("clear");
	std::cout << frame << std::endl;
	return (1);
}

int	onKeyUp(int keyCode, void *p)
{
	if (keyCode == KEY_ESC)
		exit(1);
	return (1);
}

int	main(int ac, char **av)
{
	LibX	libX = LibX(WIDTH, HEIGHT, "Hi");

	p.pos = Vector2d(250, 250);
	p.dir = Vector2d(1, 1);
	mlx_loop_hook(libX.getMlx(), &start, &libX);
	libX.onKeyUp(onKeyUp);
	libX.libXLoop();
	return (0);
}
