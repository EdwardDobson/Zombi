// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerFiring.h"

// Sets default values for this component's properties
UPlayerFiring::UPlayerFiring()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UPlayerFiring::BeginPlay()
{
	Super::BeginPlay();
	if (WeaponOne != NULL)
	{
		WeaponOne.GetDefaultObject()->Ammo = WeaponOne.GetDefaultObject()->MaxAmmo;
		m_currentWeapon = WeaponOne;
		Ammo = m_currentWeapon.GetDefaultObject()->Ammo;
	}
	if (WeaponTwo != NULL && WeaponOne != NULL)
	{
		WeaponTwo.GetDefaultObject()->Ammo = WeaponTwo.GetDefaultObject()->MaxAmmo;
	}

}

// Called every frame
void UPlayerFiring::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (m_shouldReload)
	{
		Reloading();
	}
	if (m_shouldFire)
	{
		Fire();
	}
	if (PickupWeapon)
	{
		PickupWeaponFunction();
		PickupWeapon = false;
	}
}
void UPlayerFiring::SetWorld(UWorld* _world, AActor* _player)
{
	World = _world;
	Player = _player;
}
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
void UPlayerFiring::DropWeapon()
{


}
void UPlayerFiring::Fire()
{
	if (World != NULL && m_currentWeapon != NULL)
	{
		if (m_currentWeapon.GetDefaultObject()->Ammo > 0)
		{
			m_currentWeapon.GetDefaultObject()->FireRate -= World->GetDeltaSeconds();
			if (m_currentWeapon.GetDefaultObject()->FireRate <= 0)
			{
				World->SpawnActor<ABullet>(Bullet, PlayerPos, Player->GetActorRotation());
				m_currentWeapon.GetDefaultObject()->FireRate = m_currentWeapon.GetDefaultObject()->MaxFireRateTime;
				m_currentWeapon.GetDefaultObject()->Ammo--;
		
				Ammo = m_currentWeapon.GetDefaultObject()->Ammo;
				DebugOutVector(PlayerPos.ToString());
			}
		}
	}
}

void UPlayerFiring::Reloading()
{
	
	m_currentWeapon.GetDefaultObject()->ReloadTime -= World->GetDeltaSeconds();
	if (m_currentWeapon.GetDefaultObject()->ReloadTime <= 0)
	{
		m_currentWeapon.GetDefaultObject()->Ammo = m_currentWeapon.GetDefaultObject()->MaxAmmo;
		m_currentWeapon.GetDefaultObject()->ReloadTime = m_currentWeapon.GetDefaultObject()->MaxReloadTime;
		Ammo = m_currentWeapon.GetDefaultObject()->Ammo;
		m_shouldReload = false;
	}
}
void UPlayerFiring::PickupWeaponFunction()
{
	if (WeaponOne != PickedUpWeapon && WeaponTwo != PickedUpWeapon)
	{
		if (WeaponIndex == 0)
		{
			WeaponOne = PickedUpWeapon;
			PickedUpWeapon.GetDefaultObject()->Ammo = PickedUpWeapon.GetDefaultObject()->MaxAmmo;
			SetWeaponValues(PickedUpWeapon);
		}
		if (WeaponIndex == 1)
		{
			WeaponTwo = PickedUpWeapon;
			PickedUpWeapon.GetDefaultObject()->Ammo = PickedUpWeapon.GetDefaultObject()->MaxAmmo;
			SetWeaponValues(PickedUpWeapon);
		}
	}
}

