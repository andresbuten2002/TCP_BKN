import sys
import paho.mqtt.client #libreria

def on_connect(client, userdata, flags, rc):
	print('connected (%s)' % client._client_id)
	client.subscribe(topic='labredes/aula', qos=2)

def on_message(client, userdata, message):
	print('------------------------------')
	print('topic: %s' % message.topic)
	print('payload: %s' % message.payload.decode('utf-8')) #decodificar el texto a una cadena de texto explicitamente
	print('qos: %d' % message.qos)

def main():
	client = paho.mqtt.client.Client(client_id='bocha-subs', clean_session=False)
	client.on_connect = on_connect
	client.on_message = on_message
	client.connect(host='192.168.5.168', port=1883)
	client.loop_forever()

if __name__ == '__main__':
	main()

sys.exit(0)