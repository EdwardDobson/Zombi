# Overview

When the player scrolls the weapon index change, this is done in the Base Play class. Then with the weapon index the Player Firing class can use its functions to set the correct values for the players current weapon.

[Current Features](/docs/currentfeatures.md)

## Code

<pre><code>
void UPlayerFiring::SwitchWeapon()
{
	if (WeaponIndex == 0)//Weapon One
	{
		if(WeaponOne != NULL)
		SetWeaponValues(WeaponOne);
	}
	else if (WeaponIndex == 1)	//Weapon Two
	{
		if (WeaponTwo != NULL)
		SetWeaponValues(WeaponTwo);
	}
}

void UPlayerFiring::SetWeaponValues(TSubclassOf<AGunWeapon> _otherWeapon)
{
	if (m_currentWeapon != NULL)
	{
		m_currentWeapon = _otherWeapon;
		Ammo = m_currentWeapon.GetDefaultObject()->Ammo;	
	}
}

void ABasePlay::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("Scroll", this, &ABasePlay::ChangeWeaponIndex);
}

void ABasePlay::ChangeWeaponIndex(float _value)
{
	if (PlayerFiring != NULL)
	{
		if (_value == 1)
		{
			PlayerFiring->WeaponIndex++;
			if (PlayerFiring->WeaponIndex > 1)
				PlayerFiring->WeaponIndex = 0;
			PlayerFiring->SwitchWeapon();
		}
		if (_value == -1)
		{
			PlayerFiring->WeaponIndex--;
			if (PlayerFiring->WeaponIndex < 0)
				PlayerFiring->WeaponIndex = 1;
			PlayerFiring->SwitchWeapon();
		}
	}
}
<code><pre>
