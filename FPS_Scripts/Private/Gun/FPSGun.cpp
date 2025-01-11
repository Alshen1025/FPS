// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun/FPSGun.h"
#include "FPSBullet.h"
#include <Kismet/KismetSystemLibrary.h>
#include <GamePlay/FPSCharacter.h>
#include <Kismet/GameplayStatics.h>

// Sets default values
AFPSGun::AFPSGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AFPSGun::FireBulletCPP(UClass* BulletClass, FTransform Transform)
{
	AFPSBullet* Bullet = Cast<AFPSBullet>(GetWorld()->SpawnActor(BulletClass, &Transform));
	if (Bullet)
	{
		Bullet -> SetSpeedCPP(BulletSpeedCPP);
	}
}

void AFPSGun::FireTimerCPP(float time)
{
	TimerCPP = UKismetSystemLibrary::K2_SetTimer(this, TEXT("Fire"), time, false);
}

void AFPSGun::FireReleasedCPP()
{
	IsFiredCPP = false;
	GetWorld()->GetTimerManager().ClearTimer(TimerCPP);
}

bool AFPSGun::IsFiringCPP() const
{

	return IsFiredCPP && GetWorld() -> GetTimerManager().IsTimerActive(TimerCPP);
}

void AFPSGun::MakeRecoilCPP()
{
	AFPSCharacter* Character = Cast<AFPSCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	if (Character)
	{
		float Pitch = FMath::FRandRange(-0.15, -0.05);
		Character->AddControllerPitchInput(Pitch);
		float Yaw = FMath::FRandRange(0.05, 0.15);
		Character->AddControllerYawInput(Yaw);

	}
}





// Called when the game starts or when spawned
void AFPSGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPSGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

