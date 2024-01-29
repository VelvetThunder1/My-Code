from sinric import SinricPro 
import asyncio
import psutil
 
APP_KEY = '5307cb1f-0c28-4cee-af20-48194031688a'
APP_SECRET = '2491f9ce-609c-45d5-8fff-d0693068a96b-b6e526ac-2a0a-4a48-8732-db90e0d8ee61'
SWITCH_ID = '6331228c36b44d06d4c57597'
battery = psutil.sensors_battery()

def power_state(device_id, state):
    print(device_id, state)
    return True, state
 
callbacks = {
    'powerState': power_state
}
 
if __name__ == '__main__':
    loop = asyncio.get_event_loop()
    client = SinricPro(APP_KEY, [SWITCH_ID], callbacks, enable_log=False, restore_states=False, secretKey=APP_SECRET)
    loop.run_until_complete(client.connect())

client.event_handler.raiseEvent(SWITCH_ID, 'setPowerState',data={'state': 'ON'})