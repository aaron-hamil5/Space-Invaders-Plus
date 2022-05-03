#include "BulletUpdateComponent.h"
#include "WorldState.h"

void BulletUpdateComponent::spawnForPlayer(Vector2f spawnPosition)
{
	m_MovingUp = true;
	m_BelongToPlayer = true;
	m_IsSpawned = true;

	m_TC->getLocation().x = spawnPosition.x;

	m_TC->getLocation().y = spawnPosition.y - m_TC -> getSize().y;

	m_RCC->setOrMoveCollider(m_TC->getLocation().x, m_TC->getLocation().y, m_TC->getSize().x, m_TC->getSize().y);
}

void BulletUpdateComponent::spawnForInvader(Vector2f spawnPosition)
{
	m_MovingUp = false;
	m_BelongToPlayer = false;
	m_IsSpawned = true;

	srand((int)time(0));

	m_AlienBulletSpeedModifier = (rand() % m_ModifierRandomComponent) + m_MinimumAdditionalModifier;

	m_TC->getLocation().x = spawnPosition.x;
	m_TC->getLocation().y = spawnPosition.y;

	m_RCC->setOrMoveCollider(m_TC->getLocation().x, m_TC->getLocation().y, m_TC->getSize().x, m_TC->getSize().y);
}

void BulletUpdateComponent::despawn()
{
	m_IsSpawned = false;
}

bool BulletUpdateComponent::isMovingUp()
{
	return m_MovingUp;
}

void BulletUpdateComponent::update(float FPS)
{
	if (m_IsSpawned)
	{
		if (m_MovingUp)
		{
			m_TC->getLocation().y -= m_Speed * FPS;
		} else
		{
			m_TC->getLocation().y += m_Speed / m_AlienBulletSpeedModifier * FPS;
		}

		if (m_TC->getLocation().y > WorldState::WORLD_HEIGHT || m_TC->getLocation().y < -2)
		{
			despawn();
		}

		m_RCC->setOrMoveCollider(m_TC->getLocation().x, m_TC->getLocation().y, m_TC->getSize().x, m_TC->getSize().y);
	}
}
