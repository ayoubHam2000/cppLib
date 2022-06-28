#include "LibX.hpp"

LibX::LibX(int w, int h, const std::string &title): _mlx(nullptr), _win(nullptr)
{
	_mlx = mlx_init();
	_win = mlx_new_window(_mlx, w, h, (char *)title.c_str());
	if (!_mlx || !_win)
		fatalError("LibX Error");
	mlx_hook(_win, ON_DESTROY, 0, LibX::_exit, NULL);
}

LibX::~LibX()
{
	if (_img.img)
		mlx_destroy_image(_mlx, _img.img);
}

void	 *LibX::getMlx() const
{
	return (_mlx);
}

void	 *LibX::getWin() const
{
	return (_win);
}

void	LibX::fatalError(const char *msg)
{
	std::cerr << msg << std::endl;
	exit(1);
}

int	LibX::_exit(void *ptr)
{
	exit(0);
}


void	LibX::onKeyUp(int (*p)(int keyCode, void *ptr))
{
	mlx_hook(_win, ON_KEYUP, 1L << 1, (int (*)(void *ptr))p, this);
}

void	LibX::onKeyDown(int (*p)(int keyCode, void *ptr))
{
	mlx_hook(_win, ON_KEYDOWN, 1, (int (*)(void *ptr))p, this);

}


//========================
//========================
//========================

void	LibX::createImage(int w, int h)
{
	if (_img.img)
		return ;
	_img.width = w;
	_img.height = h;
	_img.img = mlx_new_image(_mlx, w, h);
	_img.addr = mlx_get_data_addr(_img.img, &(_img.bpp), &(_img.size_line), &(_img.endian));
	if (!_img.img || !_img.addr)
		fatalError("Image Creating Error");
}

void	LibX::putPixel(int x, int y, int color)
{
	char	*dst;

	if (y >= _img.height || x >= _img.width || y < 0 || x < 0 || !_img.img)
		return ;
	dst = _img.addr + (y * _img.size_line + x * (_img.bpp / 8));
	*(unsigned int *)dst = color;
}

void	LibX::putAlphaPixel(int x, int y, int color)
{
	char			*dst;
	float			p;

	if (y >= _img.height || x >= _img.width || y < 0 || x < 0 || !_img.img)
		return ;
	dst = _img.addr + (y * _img.size_line + x * (_img.bpp / 8));
	p = ((float)((color >> 24) & 255) / 255);
	*(unsigned int *)dst = ((int)((((*(unsigned int *)dst) >> 16) & 255)
				* (1 - p) + (((color) >> 16) & 255) * (p)) << 16)
		| ((int)((((*(unsigned int *)dst) >> 8) & 255)
				* (1 - p) + (((color) >> 8) & 255) * (p)) << 8)
		| ((int)(((*(unsigned int *)dst) & 255) * (1 - p)
				+ ((color) & 255) * (p)));
}

void	LibX::flushImage(int x, int y)
{
	mlx_put_image_to_window(_mlx, _win, _img.img, x, y);
	mlx_destroy_image(_mlx, _img.img);
	_img.img = nullptr;
	_img.addr = nullptr;
}

void	LibX::putImage(int x, int y)
{
	mlx_put_image_to_window(_mlx, _win, _img.img, x, y);
}

void	LibX::libXLoop()
{
	mlx_loop(_mlx);
}
