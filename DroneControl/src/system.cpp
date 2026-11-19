#include "../inc/system.h"

void LIDAR::activate() { std::cout << "Activating LIDAR\n"; }
void LIDAR::deactivate() { std::cout << "Dectivating LIDAR\n"; }
void LIDAR::ScanEnv() { std::cout << "LIDAR is Scanning Env\n"; }

void Camera::activate() { std::cout << "Activating Camera\n"; }
void Camera::deactivate() { std::cout << "Dectivating Camera\n"; }
void Camera::PlayFeed() { std::cout << "Camera is playing feed\n"; }

void Mic::activate() { std::cout << "Activating Mic\n"; }
void Mic::deactivate() { std::cout << "Dectivating Mic\n"; }
void Mic::PlaySound() { std::cout << "Mic is playing sound\n"; }

void DroneControlStation::RegisterFeed(std::unique_ptr<IFeed> Copy_ptr)
{
    this->ptr.reset( Copy_ptr.release() );
}
void DroneControlStation::ViewFeed()
{
    IFeed * temp = this->ptr.get();
    LIDAR* loc_lidar = dynamic_cast<LIDAR*> (temp);
    if (loc_lidar)
    {
        loc_lidar->ScanEnv();
        return;
    }
    Camera* loc_camera = dynamic_cast<Camera*> (temp);
    if (loc_camera)
    {
        loc_camera->PlayFeed();
        return;
    }
    Mic* loc_mic = dynamic_cast<Mic*> (temp);
    if (loc_mic)
    {
        loc_mic->PlaySound();
        return;
    }
}
void DroneControlStation::ActivateFeed()
{
    ptr->activate();
}
void DroneControlStation::DeactivateFeed()
{
    ptr->deactivate();
}
