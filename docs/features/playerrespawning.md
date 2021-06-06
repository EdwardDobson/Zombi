# Overview

[Current Features](/docs/currentfeatures.md)

For the wave system to work the player needs to be able to respawn. The respawn mechanic was developed in C++ and the Game over screen was developed with blueprints.

## Implementation

<pre><code>
void ABasePlay::Damage(float _value)
{
	Health -= _value;
	if (Health <= 0)
	{
		Health = 50;
		Lives -= 1;
	}
}
void ABasePlay::Dead()
{
	if (Lives <= 0)
	{
		LevelName = FName(*UGameplayStatics::GetCurrentLevelName(this, true));
	}
}
</code></pre>
## Blueprint

![Game Over Blueprint](https://user-images.githubusercontent.com/47003895/120934028-9475cc80-c6f4-11eb-9f3b-899e1e3e7bb4.png)

[Here](https://blueprintue.com/blueprint/x77cpi50/) is a link to copy the blueprint.
