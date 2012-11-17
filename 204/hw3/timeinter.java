//Interface that tells people the time periodically

public interface TimeClient {

    public void setTime( int hour, int minute, int second ) ;
    public void setData( int day, int month, int year ) ;
    public void setBoth( int hour, int minute, int second, int day, int month, int year ) ; 

}




