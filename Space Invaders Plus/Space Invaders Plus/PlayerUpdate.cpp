#include "PlayerUpdateComponent.h"
#include "WorldState.h"

void PlayerUpdateComponent::update(float FPS)
{
	if (sf::Joystick::isConnected(0))
	{
		m_TC->getLocation().x += ((m_Speed / 100) * m_XExtent) * FPS;
		m_TC->getLocation().y += ((m_Speed / 100) * m_XExtent) * FPS;
	}

	if (m_IsHoldingLeft)
	{
		m_TC->getLocation().x -= m_Speed * FPS;
	}
	else if (m_IsHoldingRight)
	{
		m_TC->getLocation().x += m_Speed * FPS;
	}

	if (m_IsHoldingUp)
	{
		m_TC->getLocation().y -= m_Speed * FPS;
	}
	else if (m_IsHoldingDown)
	{
		m_TC->getLocation().y += m_Speed * FPS;
	}

	m_RCC->setOrMoveCollider(m_TC->getLocation().x, m_TC->getLocation().y, m_TC->getSize().x, m_TC->getSize().y);

	if (m_TC->getLocation().x > WorldState::WORLD_WIDTH - m_TC->getSize().x)
	{
		m_TC->getLocation().x = WorldState::WORLD_WIDTH - m_TC->getSize().x;
	}
	else if (m_TC->getLocation().x < 0)
	{
		m_TC->getLocation().x = 0;
	}

	if (m_TC->getLocation().y > WorldState::WORLD_HEIGHT - m_TC->getSize().y)
	{
		m_TC->getLocation().y = WorldState::WORLD_HEIGHT - m_TC->getSize().y;
	}
	else if (m_TC->getLocation().y < WorldState::WORLD_HEIGHT / 2)
	{
		m_TC->getLocation().y = WorldState::WORLD_HEIGHT / 2;
	}
}


	void PlayerUpdateComponent::updateShipTravelWithController(float x, float y)
	{
		m_XExtent = x;
		m_YExtent = y;
	}

	void PlayerUpdateComponent::moveLeft()
	{
		m_IsHoldingLeft = true;
		stopRight();
	}

	void PlayerUpdateComponent::moveRight()
	{
		m_IsHoldingRight = true;
		stopLeft();
	}

	void PlayerUpdateComponent::moveUp()
	{
		m_IsHoldingUp = true;
		stopDown();
	}

	void PlayerUpdateComponent::moveDown()
	{
		m_IsHoldingDown = true;
		stopUp();
	}


	void PlayerUpdateComponent::stopLeft()
	{
		m_IsHoldingLeft = false;
	}

	void PlayerUpdateComponent::stopRight()
	{
		m_IsHoldingRight = false;
	}

	void PlayerUpdateComponent::stopUp()
	{
		m_IsHoldingUp = false;
	}

	void PlayerUpdateComponent::stopDown()
	{
		m_IsHoldingDown = false;

	}
