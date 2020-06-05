// from : http://www.automatic-pilot.com/midifile.html

/*	How to write a java program that writes a MIDI file
 *	Here is a very short java program that writes a midi file that will play on any modern MIDI player including most computer sound cards. 
 *	This is not intended as a tutorial on the MIDI spec, nor the javax.sound.midi package, but rather as a simple demo of how it's done.
 */

//--------------------------------------------

/**
 * midifile.java
 *
 * A very short program which builds and writes
 * a one-note Midi file.
 *
 * author  Karl Brown
 * last updated 2/24/2003
 */

import java.io.*;
import java.util.*;
import javax.sound.midi.*; // package for all midi classes

public class writeMide {
	public static void main(String argv[]) {
		System.out.println("midifile begin ");
		try{
	//****  Create a new MIDI sequence with 24 ticks per beat  ****
			Sequence s = new Sequence(javax.sound.midi.Sequence.PPQ,24);

	//****  Obtain a MIDI track from the sequence  ****
			Track t = s.createTrack();

	//****  General MIDI sysex -- turn on General MIDI sound set  ****
			byte[] b = {(byte)0xF0, 0x7E, 0x7F, 0x09, 0x01, (byte)0xF7};
			SysexMessage sm = new SysexMessage();
			sm.setMessage(b, 6);
			MidiEvent me = new MidiEvent(sm,(long)0);
			t.add(me);

	//****  set tempo (meta event)  ****
			MetaMessage mt = new MetaMessage();
	        byte[] bt = {0x02, (byte)0x00, 0x00};
			mt.setMessage(0x51 ,bt, 3);
			me = new MidiEvent(mt,(long)0);
			t.add(me);

	//****  set track name (meta event)  ****
			mt = new MetaMessage();
			String TrackName = new String("midifile track");
			mt.setMessage(0x03 ,TrackName.getBytes(), TrackName.length());
			me = new MidiEvent(mt,(long)0);
			t.add(me);

	//****  set omni on  ****
			ShortMessage mm = new ShortMessage();
			mm.setMessage(0xB0, 0x7D,0x00);
			me = new MidiEvent(mm,(long)0);
			t.add(me);

	//****  set poly on  ****
			mm = new ShortMessage();
			mm.setMessage(0xB0, 0x7F,0x00);
			me = new MidiEvent(mm,(long)0);
			t.add(me);

	//****  set instrument to Piano  ****
			mm = new ShortMessage();
			mm.setMessage(0xC0, 0x00, 0x00);
			me = new MidiEvent(mm,(long)0);
			t.add(me);

	//****  note on - middle C  ****
			mm = new ShortMessage();
			mm.setMessage(0x90,0x3C,0x60);
			me = new MidiEvent(mm,(long)1);
			t.add(me);

	//****  note off - middle C - 120 ticks later  ****
			mm = new ShortMessage();
			mm.setMessage(0x80,0x3C,0x40);
			me = new MidiEvent(mm,(long)121);
			t.add(me);

	//****  set end of track (meta event) 19 ticks later  ****
			mt = new MetaMessage();
			byte[] bet = {}; // empty array
			mt.setMessage(0x2F,bet,0);
			me = new MidiEvent(mt, (long)140);
			t.add(me);

	//****  write the MIDI sequence to a MIDI file  ****
			File f = new File("midifile.mid");
			MidiSystem.write(s,1,f);
		} //try
			catch(Exception e)
		{
			System.out.println("Exception caught " + e.toString());
		} //catch
		System.out.println("midifile end ");
	} //main
}