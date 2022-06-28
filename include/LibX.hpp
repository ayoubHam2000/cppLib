#ifndef LIB_X_HPP
#define LIB_X_HPP

#include <iostream>
#include "mlx_c.h"

#define WIDTH 500
#define HEIGHT 500

struct	Image
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;

	Image(): img(nullptr), addr(nullptr) {}
};

class	LibX
{
private:
	void	*_mlx;
	void	*_win;
	int		_keys[10];
	Image	_img;

	void	fatalError(const char *msg);
	static int	_exit(void *ptr);
public:
	LibX(int w, int h, const std::string &title);
	~LibX();
	void	*getMlx() const;
	void	*getWin() const;

	void	createImage(int w, int h);
	void	putPixel(int x, int y, int color);
	void	putAlphaPixel(int x, int y, int color);
	void	flushImage(int x, int y);
	void	putImage(int x, int y);
	void	libXLoop();
	void	onKeyUp(int (*p)(int keyCode, void *ptr));
	void	onKeyDown(int (*p)(int keyCode, void *ptr));
};

#endif
