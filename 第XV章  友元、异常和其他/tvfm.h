// tvfm.h -- Tv and Remote classes using a friend member
#pragma once

class TvFm;			// forward declaration

class RemoteFm
{
public:
	enum State{ Off, On };
	enum { MinVal, MaxVal = 20 };
	enum { Antenna, Cable };
	enum { TV, DVD };
private:
	int mode;
public:
	RemoteFm(int m = TV) : mode(m) {}
	bool volup(TvFm& t);		// prototype only
	bool voldown(TvFm& t);
	void onoff(TvFm& t);
	void chanup(TvFm& t);
	void chandown(TvFm& t);
	void set_mode(TvFm& t);
	void set_input(TvFm& t);
	void set_chan(TvFm& t, int c);
};

class TvFm
{
public:
	friend void RemoteFm::set_chan(TvFm& t, int c);
	enum State{ Off, On };
	enum { MinVal, MaxVal = 20 };
	enum { Antenna, Cable };
	enum { TV, DVD };

	TvFm(int s = Off, int mc = 125) :state(s), volume(5),
		maxchannel(mc), channel(2), mode(Cable), input(TV) {}
	void onoff() { state = (state == On) ? Off : On; }
	bool ison() const { return state == On; }
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() { mode = (mode == Antenna) ? Cable : Antenna; }
	void set_input() { input = (input == TV) ? DVD : TV; }
	void settings() const;	// display all settings

private:
	int state;             // on or off
	int volume;            // assumed to be digitized
	int maxchannel;        // maximum number of channels
	int channel;           // current channel setting
	int mode;              // broadcast or cable
	int input;             // TV or DVD
};

// Remote methods as inline functions
inline bool RemoteFm::volup(TvFm& t) { return t.volup(); }
inline bool RemoteFm::voldown(TvFm& t) { return t.voldown(); }
inline void RemoteFm::onoff(TvFm& t) { t.onoff(); }
inline void RemoteFm::chanup(TvFm& t) { t.chanup(); }
inline void RemoteFm::chandown(TvFm& t) { t.chandown(); }
inline void RemoteFm::set_mode(TvFm& t) { t.set_mode(); }
inline void RemoteFm::set_input(TvFm& t) { t.set_input(); }
inline void RemoteFm::set_chan(TvFm& t, int c) { t.channel = c; }

