# Sistema de Monitoreo de IoT con MQTT, Node-RED, InfluxDB, Grafana y Home Assistant.

## Resumen

El proyecto tiene como objetivo desarrollar un sistema completo de monitoreo de IoT que capture y almacene los datos de temperatura y uso de CPU de servidores, y proporcione visualizaciones en tiempo real y automatización a través de diferentes componentes. Se utilizarán tecnologías como MQTT, Node-RED del lado del servidor y python y bash del lado de los clientes.

Objetivo general: Implementar un sistema integral de monitoreo de IoT que permita capturar, almacenar y visualizar los datos de temperatura y uso de CPU de servidores.

En primer lugar, se configura un entorno de Docker y Docker compose con el fin de definir los servicios de Noder-Red y EMQX.
El archivo correspondiente a `docker-compose.yml` esta compuesto por dos partes principales debido a los dos servicios.

```yml
services:
  emqx:
    image: emqx:5.6.1     #imagen de Dokcer que se utilizará para el servicio
    container_name: emqx  #nombre del contenedor
    environment:          #creacion de variables de entorno para configurar el servicio
    - "EMQX_NODE_NAME=emqx@node1.emqx.io"   #nombre del nodo EMQX
    - "EMQX_CLUSTER__DISCOVERY_STRATEGY=static"   #estrategia de descubrimiento de clúster EMQX
    - "EMQX_CLUSTER__STATIC__SEEDS=[emqx@node1.emqx.io,emqx@node2.emqx.io]"   #nodos semilla del clúster EMQX
    healthcheck:  #comprobación de salud del contenedor
      test: ["CMD", "/opt/emqx/bin/emqx", "ctl", "status"]
      interval: 5s  #intervalo entre comprobaciones
      timeout: 25s  #tiempo maximo de espera para una comprobacion de salud
      retries: 5    #intentos de comprobación de salud
    networks:     #configuración de red
      emqx-bridge:
        aliases:
        - node1.emqx.io
    ports:      #mapeo de puertos
      - 1883:1883
      - 8083:8083
      - 8084:8084
      - 8883:8883
      - 18083:18083 

networks: #definicion de redes
  emqx-bridge:
    driver: bridge
```
En esta sección, se define un servicio llamado emqx que utiliza la imagen emqx:5.6.1, configura variables de entorno para el servicio EMQX, establece una comprobación de salud para el contenedor EMQX, configura la red para el contenedor y mapea los puertos entre el host y el contenedor. También define una red llamada emqx-bridge con el tipo de driver bridge.

Por otro lado, tenemos la parte del código referente al servicio de Node-Red.
```yml
services:
  node-red:
    image: nodered/node-red:latest # La imagen Docker que se utilizará para el servicio Node-RED, en este caso, la última versión disponible de Node-RED
    environment: # Variables de entorno para configurar el servicio Node-RED
      - TZ=Europe/Amsterdam
    ports: # Mapeo de puertos entre el host y el contenedor Node-RED
      - "1880:1880"
    networks: # Configuración de la red para el servicio Node-RED
      - node-red-net
    volumes: # Configuración de volúmenes para el servicio Node-RED
      - ./data:/data # Monta el directorio local './data' en el directorio '/data' dentro del contenedor

networks: #definicion de redes
  node-red-net:
    driver: bridge
```
En resumen, este archivo Docker Compose define un servicio llamado node-red que utiliza la imagen nodered/node-red:latest, configura la zona horaria del contenedor como Europe/Amsterdam, mapea el puerto 1880 del host al puerto 1880 del contenedor, asigna el servicio a una red llamada node-red-net, y monta el directorio local ./data en el directorio /data dentro del contenedor. Además, define una red llamada node-red-net con el tipo de driver bridge.

El archivo completo se encuentra en este repositorio: [docker-compose.yml](https://github.com/andresbuten2002/TCP_BKN/blob/main/actividades_dani_08052024/actividad_1/docker-compose.yml).

Posteriormente, se puede implementar el comando de Docker Compose para desplegar los contenedores de Node-Red y EMQX:
```bash
docker-compose up -d
```
Cabe mencionar de gran importancia dar permisos necesarios a la carpeta `/data` con la cual se creó el volumen.
```bash
chmod o+w data
```

Una vez que ya se tienen los contenedores levantados y corriendo, se puede acceder al flujo de Node-Red para agregar publicadores y suscriptores según el tópico deseado.

Par acceder al mismo, en un navegador nos situamos en la dirección donde esta levantado el contenedor y el puerto 1880.


### docker mosquitto
- probar (hecha por mi): docker run -it -v /etc/mosquitto/mosquitto.conf:/etc/mosquitto/mosquitto.conf -p 1883:1883 -d mosquitto:1.0
https://cedalo.com/blog/mosquitto-docker-configuration-ultimate-guide/
### docker node-red
https://nodered.org/docs/getting-started/docker
chmod o+w data

### docker emqx 
https://www.emqx.io/docs/en/latest/deploy/install-docker.html
CAMBIAMOS PUERTO 1883->>1884 para que no se superonga con mosquitto
> docker run -d --name emqx -p 1884:1884 -p 8083:8083 -p 8084:8084 -p 8883:8883 -p 18083:18083  emqx:5.6.1 




## Milestone 2: Aprovisionamiento de configuraciones

1. Configurar las credenciales y configuraciones específicas de Node-RED, como la configuración de conexión a EMQX y otros nodos necesarios.
2. Aprovisionar los archivos de configuración necesarios para EMQX, como los archivos de configuración general, autenticación y tópicos MQTT.
3. Reiniciar los contenedores de Node-RED y EMQX para aplicar las nuevas configuraciones.

## Milestone 3: Creación del cliente Bash

1. Crear un archivo Bash que utilice el comando `lm-sensors` para obtener la información de temperatura y uso de CPU.
2. Configurar el cliente Bash para publicar los datos obtenidos en un tópico MQTT específico en el broker EMQX.

## Milestone 4: Creación del cliente Python

1. Crear un script en Python que utilice la librería Paho para conectarse al broker EMQX.
2. Implementar la lógica necesaria para obtener la información de temperatura y uso de CPU utilizando `lm-sensors`.
3. Configurar el cliente Python para publicar los datos obtenidos en un tópico MQTT específico en el broker EMQX.

Cada milestone representa un hito importante en el proceso de despliegue y configuración. Al completar estos milestones, habrás desplegado Node-RED y EMQX como servicios, aprovisionado sus configuraciones y creado los clientes Bash y Python para enviar la información de lm-sensors al broker MQTT.

### Pasos previos
1. Instalar libreria mqtt para python:
```shell
pip install --user paho-mqtt
```


### QoS
El QoS (Quality of Service o Calidad de Servicio) en MQTT (Message Queuing Telemetry Transport) es un mecanismo que garantiza la entrega confiable de mensajes entre el cliente y el servidor (broker). El QoS especifica el nivel de garantía que se proporciona con respecto a la entrega de un mensaje. Hay tres niveles de QoS en MQTT:

- QoS 0 (At most once): Este es el nivel de QoS más bajo. El mensaje se entrega al menos una vez o nunca. No hay garantía de entrega, ya que el mensaje se envía sin confirmación y se entrega de manera "lo más seguro posible". Este nivel de QoS es el más rápido y menos confiable.
- QoS 1 (At least once): En este nivel de QoS, el mensaje se entrega al menos una vez. Si el mensaje no se entrega correctamente (por ejemplo, si se pierde durante la transmisión), el cliente lo volverá a enviar hasta que reciba una confirmación de entrega del servidor. Esto garantiza que no se pierdan mensajes, pero puede resultar en duplicados.
- QoS 2 (Exactly once): Este nivel de QoS proporciona la entrega exactamente una vez. Se realiza un intercambio de confirmación de cuatro pasos entre el cliente y el servidor para garantizar que el mensaje se entregue solo una vez. Este nivel de QoS es el más lento pero el más confiable, ya que garantiza que no haya duplicados ni pérdidas.