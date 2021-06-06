# Overview

To help with implementing functions that are long I have created some macros. These macros help outputting values for debugging.

## Code

<pre><code>
#define DebugOut(x) 	if(GEngine){GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, FString(x));}
#define DebugOutFloat(x) 	if(GEngine){GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, FString::SanitizeFloat(x));}
#define DebugOutInt(x) 	if(GEngine){GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, FString::FromInt(x));}
#define DebugOutVector(x) 	if(GEngine){GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, FString(x));}
</code></pre>
