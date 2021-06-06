# Overview

[Current Features](/docs/currentfeatures.md)

## Code
<pre><code>
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
void ABasePlay::SetPickedUpWeapon(TSubclassOf<AGunWeapon> _weapon)
{
	PickedUpWeapon = _weapon;
}
</code></pre>
## Blueprint
![Weaponpickup blueprint](https://user-images.githubusercontent.com/47003895/120934605-e3bcfc80-c6f6-11eb-9722-bc41ef9adf82.png)
[Here](https://blueprintue.com/blueprint/gbsotcvk/) is a link to copy the blueprint.
