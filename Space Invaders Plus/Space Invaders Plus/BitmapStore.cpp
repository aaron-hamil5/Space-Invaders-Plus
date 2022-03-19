#include "BitmapStore.h"
#include <assert.h>
#include <iostream>

using namespace sf;

BitmapStore* BitmapStore::m_s_instance = nullptr;

BitmapStore::BitmapStore()
{
	assert(m_s_instance == nullptr);
	m_s_instance = this;
}

void BitmapStore::addBitmap(std::string const& filename)
{
	auto& bitmapsMap = m_s_instance->m_BitmapMap;
	auto keyValuePair = bitmapsMap.find(filename);

	if (keyValuePair == bitmapsMap.end())
	{
		auto& texture = bitmapsMap[filename];
		texture.loadFromFile(filename);
	}

}

sf::Texture& BitmapStore::getBitmap(std::string const& filename)
{
	auto& m = m_s_instance->m_BitmapMap;
	auto keyValuePair = m.find(filename);

	if (keyValuePair != m.end())
	{
		return keyValuePair->second;
	}
	else
	{
#ifndef debuggingConsole
		std::cout << "BitmapStore::getBitmap() Texture Not Found!" << std::endl;
#endif debuggingConsole


		return keyValuePair->second;
	}
}