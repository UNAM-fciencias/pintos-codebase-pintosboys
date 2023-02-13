$DOCKER_IMAGE_BACKUP = "alainchevanier/so-20231-pintos"
Write-Host "Starting session in container"
docker run -it --volume ${pwd}:/app --workdir /app --rm $DOCKER_IMAGE_BACKUP bash
