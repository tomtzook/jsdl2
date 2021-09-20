package sdl2.events;

public class JBallMotionEvent extends Event {

    private final int mJoystickId;
    private final int mBall;
    private final int mXValue;
    private final int mYValue;

    public JBallMotionEvent(int joystickId, int ball, int xValue, int yValue) {
        super(EventType.JOY_BALL_MOTION);
        mJoystickId = joystickId;
        mBall = ball;
        mXValue = xValue;
        mYValue = yValue;
    }

    public int getJoystickId() {
        return mJoystickId;
    }

    public int getBall() {
        return mBall;
    }

    public int getXValue() {
        return mXValue;
    }

    public int getYValue() {
        return mYValue;
    }
}
