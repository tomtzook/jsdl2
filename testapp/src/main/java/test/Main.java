package test;

import sdl2.EventsJni;
import sdl2.GameControllerJni;
import sdl2.JoystickJni;
import sdl2.SdlJni;
import sdl2.events.AxisMotionEvent;
import sdl2.events.DeviceConnectionEvent;
import sdl2.events.Event;

import java.util.Map;

public class Main {

    static long[] sDevices = new long[10];
    static int[][] sAxes = new int[10][10];

    public static void main(String[] args) {
        System.load("/home/tomtzook/projects/tryouts/flashlib-plugins/build/sdl/cmake/libsdl_jni.so");

        int result = SdlJni.init(SdlJni.INIT_GAMECONTROLLER | SdlJni.INIT_JOYSTICK);
        if (result != 0) {
            System.err.printf("init error (%d)\n", result);
            String error = SdlJni.getError();
            System.err.printf("\t%s\n", error);
            return;
        }

        try {
            while (true) {
                Event event = EventsJni.waitEventTimeout(5000);
                if (event == null) {
                    System.err.printf("Null event\n");
                    continue;
                }

                AxisMotionEvent motionEvent;
                DeviceConnectionEvent connectionEvent;
                switch (event.getType()) {
                    case CONTROLLERAXISMOTION:
                        motionEvent = (AxisMotionEvent) event;
                        System.out.printf("[CONTROLLER] Axis Motion: id=%d, axis=%d, value=%d\n",
                                motionEvent.getJoystickId(), motionEvent.getAxis(),
                                motionEvent.getValue());
                        break;
                    case JOYAXISMOTION:
                        motionEvent = (AxisMotionEvent) event;
                        System.out.printf("[JOYSTICK] Axis Motion: id=%d, axis=%d, value=%d\n",
                                motionEvent.getJoystickId(), motionEvent.getAxis(),
                                motionEvent.getValue());
                        break;
                    case CONTROLLERDEVICEADDED:
                    case CONTROLLERDEVICEREMOVED:
                        connectionEvent = (DeviceConnectionEvent) event;
                        if (connectionEvent.isConnected()) {
                            System.out.printf("[CONTROLLER] Connected: id=%d\n", connectionEvent.getDeviceIndex());
                            long ptr = GameControllerJni.open(connectionEvent.getDeviceIndex());
                            int id = JoystickJni.getInstanceId(GameControllerJni.getJoystick(ptr));
                            System.out.printf("\tname: %s, id=%d\n", GameControllerJni.getName(ptr), id);
                            sDevices[id] = ptr;
                        } else {
                            int id = JoystickJni.getDeviceInstanceId(connectionEvent.getDeviceIndex());
                            System.out.printf("[CONTROLLER] Disconnected: id=%d %d\n", connectionEvent.getDeviceIndex(),
                                    id);
                        }
                        break;
                    case JOYDEVICEADDED:
                    case JOYDEVICEREMOVED:
                        connectionEvent = (DeviceConnectionEvent) event;
                        if (connectionEvent.isConnected()) {
                            System.out.printf("[JOYSTICK] Connected: id=%d\n", connectionEvent.getDeviceIndex());
                            long ptr = JoystickJni.open(connectionEvent.getDeviceIndex());
                            System.out.printf("\tname: %s\n", JoystickJni.getName(ptr));
                        } else {
                            System.out.printf("[JOYSTICK] Disconnected: id=%d\n", connectionEvent.getDeviceIndex());
                        }
                        break;
                }
            }
        } finally {
            SdlJni.quit();
        }
    }
}
