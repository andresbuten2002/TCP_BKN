FROM ubuntu:22.04

# Establecer directorio de trabajo
WORKDIR /home

# Actualizar lista de paquetes e instalar herramientas
RUN apt-get update -y
RUN apt-get install mosquitto -y
RUN apt-get install mosquitto-clients -y

# Especificar el comando predeterminado al iniciar el contenedor
CMD ["bash"]