// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun/FPSBullet.h"

// Sets default values
AFPSBullet::AFPSBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BulletCPP = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BulletCPP"));
	if (BulletCPP)
	{
		RootComponent = BulletCPP;
	}
}

void AFPSBullet::SetSpeedCPP(float value)
{
	SpeedCPP = value;
}
// Called when the game starts or when spawned
void AFPSBullet::BeginPlay()
{
	Super::BeginPlay();
	if (BulletCPP)
	{
		BulletCPP->OnComponentHit.AddUniqueDynamic(this, &AFPSBullet::OnHitCallback);
	}
	
}

void AFPSBullet::OnHitCallback(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	Destroy();
}

// Called every frame
void AFPSBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

