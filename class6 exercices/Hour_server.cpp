#include "ros/ros.h" /*	*/
#include "class_6/hour.h" /* On r�cup�re le service cr�� */
#include <time.h> /* Biblioth�que permettant de r�cup�rer les donn�es de temps */

time_t theTime = time(NULL);
struct tm *aTime = localtime(&theTime);

bool heure(class_6::hour::Request  &req,
         class_6::hour::Response &res)
{
  res.hour = aTime->tm_hour; /* On impl�mente l'heure dans la variable de sortiedu service */
  ROS_INFO("Envoie de l'heure");
  return true;
}

/*
*/

int main(int argc, char **argv)
{
  ros::init(argc, argv, "hour_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("hour", heure);
  ROS_INFO("Pr�t � envoyer l'heure");
  ros::spin();

  return 0;
}
