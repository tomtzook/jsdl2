package test;

import sdl2.GameControllerJni;
import sdl2.JoystickJni;
import sdl2.JoystickType;
import sdl2.SdlJni;

public class Main {

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

            long ptr = JoystickJni.open(0);
            if (ptr == 0) {
                System.err.printf("open error (%d)\n", result);
                String error = SdlJni.getError();
                System.err.printf("\t%s\n", error);
                return;
            }

            int axes = JoystickJni.getNumAxes(ptr);
            int buttons = JoystickJni.getNumButtons(ptr);
            int hats = JoystickJni.getNumHats(ptr);
            int balls = JoystickJni.getNumBalls(ptr);

            int isGamepad = GameControllerJni.isGameController(0);

            System.out.printf("JOY 0x%x: axes: %d, buttons: %d, hats: %d, balls: %d, gamepad? %d\n",
                    ptr, axes, buttons, hats, balls, isGamepad);

            for (int i = 0; i < axes; i++) {
                int value = JoystickJni.getAxis(ptr, i);
                System.out.printf("\tAxis %d: %d\n", i, value);
            }
        } finally {
            SdlJni.quit();
        }
    }
}
