#ifndef BitmapStore_H
#define BitmapStore_H

#include <SFML/Graphics.hpp>
#include <map>

class BitmapStore {
private:
	std::map<std::string, sf::Texture> m_BitmapMap;
	static BitmapStore* m_s_instance;

public:
	BitmapStore();

	static sf::Texture& getBitmap(std::string const& filename);
	static void addBitmap(std::string const& filename);
};
#endif BitmapStore_H