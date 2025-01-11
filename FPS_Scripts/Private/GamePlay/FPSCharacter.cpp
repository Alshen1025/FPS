// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlay/FPSCharacter.h"
#include <GameFramework/CharacterMovementComponent.h>
#include <EnhancedInputComponent.h>
#include <FPSGameUserSettings.h>

// Sets default values
AFPSCharacter::AFPSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ShadowBodyCPP = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("ShadowBodyCPP"));
	if (ShadowBodyCPP)
	{
		ShadowBodyCPP->SetupAttachment(RootComponent);
	}

	LowerBodyCPP = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("LowerBodyCPP"));
	if (LowerBodyCPP)
	{
		LowerBodyCPP->SetupAttachment(RootComponent);
	}
	

	CameraCPP = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraCPP"));
	if (CameraCPP)
	{
		CameraCPP->SetupAttachment(RootComponent);
		FirstPersonCPP = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FirstPersonCPP"));
		if (FirstPersonCPP)
		{
			FirstPersonCPP->SetupAttachment(CameraCPP);
			ChildActorBackCPP = CreateDefaultSubobject<UChildActorComponent>(TEXT("ChildActorBackCPP"));
			if (ChildActorBackCPP)
			{
				ChildActorBackCPP->SetupAttachment(FirstPersonCPP);
			}
			ChildActorHandCPP = CreateDefaultSubobject<UChildActorComponent>(TEXT("ChildActorHandCPP"));
			if (ChildActorHandCPP)
			{
				ChildActorHandCPP->SetupAttachment(FirstPersonCPP);
			}
		}
	}
}
float AFPSCharacter::GetSpeedCPP() const
{
	return GetVelocity().Length();
}

bool AFPSCharacter::CanRunCPP() const
{
	return (MoveForwardValueCPP>0.0 && IsRunPressedCPP);
}

void AFPSCharacter::TickRunCPP()
{
	if (CanRunCPP())
	{
		switch (StateCPP)
		{
		case StateOfCharacterCPP::Idle:
			StateCPP = StateOfCharacterCPP::Running;
			GetCharacterMovement()->MaxWalkSpeed *= 2.0;
		}
	}
	else
	{
		switch (StateCPP)
		{
		case StateOfCharacterCPP::Running:
			StateCPP = StateOfCharacterCPP::Idle;
			GetCharacterMovement()->MaxWalkSpeed *= 0.5;
		}
	}
}

void AFPSCharacter::OnTriggerRun(const FInputActionValue& Value)
{
	IsRunPressedCPP = Value.Get<bool>();
}

void AFPSCharacter::OnTriggerTurnPitch(const FInputActionValue& Value)
{
	UFPSGameUserSettings* UserSettings = Cast<UFPSGameUserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings)
	{
		float Pitch = UserSettings->GetMouseSensitivity() * Value.Get<float>();
		AddControllerPitchInput(Pitch);
	}
}

void AFPSCharacter::OnTriggerTurnYaw(const FInputActionValue& Value)
{
	UFPSGameUserSettings* UserSettings = Cast<UFPSGameUserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings)
	{
		float Yaw = UserSettings->GetMouseSensitivity() * Value.Get<float>();
		AddControllerYawInput(Yaw);
	}
}

// Called when the game starts or when spawnedh   
void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();
	TickRunCPP();
	
}

void AFPSCharacter::Brightness()
{
	float Brightness = 0.0;
	UFPSGameUserSettings* UserSettings = Cast<UFPSGameUserSettings>(GEngine->GetGameUserSettings());
	if (UserSettings)
	{
		Brightness = UserSettings->GetAutoEcposureBrightness();
	}
	if (CameraCPP)
	{
		FPostProcessSettings Settings = CameraCPP->PostProcessSettings;
		Settings.AutoExposureMinBrightness = Brightness;
		Settings.AutoExposureMaxBrightness = Brightness;
		CameraCPP->PostProcessSettings = Settings;
	}
}

// Called every frame
void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Brightness();
}

// Called to bind functionality to input
void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(RunInputAction, ETriggerEvent::Triggered, this, &AFPSCharacter::OnTriggerRun);
		EnhancedInputComponent->BindAction(TrunPitchInputAction, ETriggerEvent::Triggered, this, &AFPSCharacter::OnTriggerTurnPitch);
		EnhancedInputComponent->BindAction(TurnYawInputAction, ETriggerEvent::Triggered, this, &AFPSCharacter::OnTriggerTurnYaw);
	}
}

