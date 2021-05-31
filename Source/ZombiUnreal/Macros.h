#pragma once

#include "CoreMinimal.h"
#define DebugOut(x) 	if(GEngine){GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, FString(x));}
#define DebugOutFloat(x) 	if(GEngine){GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, FString::SanitizeFloat(x));}
#define DebugOutInt(x) 	if(GEngine){GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, FString::FromInt(x));}
#define DebugOutVector(x) 	if(GEngine){GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, FString(x));}

class ZOMBIUNREAL_API Macros
{
public:
	Macros();
	~Macros();
};
