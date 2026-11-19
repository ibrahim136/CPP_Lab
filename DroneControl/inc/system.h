#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include <iostream>
#include <memory>

class IFeed
{
    public:
    virtual void activate() =0;
    virtual void deactivate() =0;
};

class LIDAR : public IFeed
{
    public:
    void activate() override;
    void deactivate() override;
    void ScanEnv();
};

class Camera : public IFeed
{
    public:
    void activate() override;
    void deactivate() override;
    void PlayFeed();
};

class Mic : public IFeed
{
    public:
    void activate() override;
    void deactivate() override;
    void PlaySound();
};

class DroneControlStation
{
    private:
    std::unique_ptr<IFeed> ptr;
    public:
    void RegisterFeed(std::unique_ptr<IFeed> Copy_ptr);
    void ViewFeed();
    void ActivateFeed();
    void DeactivateFeed();
};

#endif