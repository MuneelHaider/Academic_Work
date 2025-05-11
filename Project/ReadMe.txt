Backend:

Prepared Dockerfile for the server side code.
On AWS, launched an instance of EC2.
Using CMD, copied the project files to to EC2.
Installed Docker on EC2.
Containerized the project and up'd the docker containers on EC2.
EC2 deployment complete.
Backend server now accessible at http://13.201.189.137:5000/api

URL: 13.201.189.137/api/

Frontend:

Used npm run build to build it for production.
Updated package.json for nginx
Updated .env to use the new backend URL.
On AWS, created a new environment and application for the frontend using AWS Elastic Beanstalk.
On AWS, the new environment is created.
The frontend is now communicating with back.

URL: Bloodhubb-front-env.eba-ruucqppz.ap-south-1.elasticbeanstalk.com

GitHub: https://github.com/MuneelHaider/BloodHub