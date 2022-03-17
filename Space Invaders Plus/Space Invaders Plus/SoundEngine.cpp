#include "SoundEngine.h"

#include <cassert>

using namespace sf;

SoundEngine* SoundEngine::m_s_instance = nullptr;

SoundEngine::SoundEngine()
{
	assert(m_s_instance == nullptr);
	m_s_instance = this;

	m_ShootBuffer.loadFromFile("assets/sound/shoot.ogg");
	m_PlayerExplodeBuffer.loadFromFile("assets/sound/shoot.ogg");
	m_InvaderExplodeBuffer.loadFromFile("assets/sound/shoot.ogg");
	m_ClickBuffer.loadFromFile("assets/sound/shoot.ogg");

	m_ShootSound.setBuffer(m_ShootBuffer);
	m_PlayerExplodeSound.setBuffer(m_PlayerExplodeBuffer);
	m_InvaderExplodeSound.setBuffer(m_InvaderExplodeBuffer);
	m_ShootSound.setBuffer(m_ClickBuffer);
}

void SoundEngine::playShoot()
{
	m_s_instance->m_ShootSound.play();
}

void SoundEngine::playPlayerExplode()
{
	m_s_instance->m_PlayerExplodeSound.play();
}

void SoundEngine::playInvaderExplode()
{
	m_s_instance->m_InvaderExplodeSound.play();
}

void SoundEngine::playClick()
{
	m_s_instance->m_ClickSound.play();
}
