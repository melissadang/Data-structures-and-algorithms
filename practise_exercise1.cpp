// Student Name & Number: Melissa Dang, 20789879
// Student Name & Number: Carol Liu, 20766616
//
// SYDE 223 Lab: 01 Assignment: 01
// Filename: practise_exercise1.cpp
//
// We hereby declare that this code, submitted for credit for the course
// SYDE223, is a product of our own efforts.  This coded solution has
// not been plagiarized from other sources and has not been knowingly
// plagiarized by others.
//
// Project: Software Application for Creating Music Playlist
// Purpose: Designing a softwre application for creating music playlists.
// Due Date: 01/17/20
//*********************************************************************************

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

// Step1. Music class
class Music {
	string artist_name;
	unsigned int year_made;
	string music_id;
	
public:
	Music ();
	Music (string new_name, unsigned int new_year, string new_id);
	bool operator==(Music& target) const;
	string get_artist();
	
};

Music::Music(): artist_name("n/a"), year_made(0), music_id("n/a") {
	
}

Music::Music(string new_name, unsigned int new_year, string new_id): artist_name(new_name),
	year_made(new_year), music_id(new_id) {
		
}

bool Music::operator==(Music& target) const {
	bool identical = true;
	identical = identical && (artist_name == target.artist_name);
	identical = identical && (year_made == target.year_made);
	identical = identical && (music_id == target.music_id);
	return identical;
}

string Music::get_artist() {
	return artist_name;
}

// Step2. Song class
class Song : public Music {
	string genre;
	string song_name;
	unsigned int length;

public:
	Song();
	Song(string new_name, unsigned int new_year, string new_id, string new_genre, string new_song_name,
	        unsigned int new_length);
	bool operator==(Song& target) const;
	string get_genre();
	string get_song_name();
	string get_length();
	
};

Song::Song(): artist_name("n/a"), year_made(0), music_id("n/a"), genre("n/a"), song_name("n/a"), length(0) {
	
}

Song::Song(string new_name, unsigned int new_year, string new_id,
        string new_genre, string new_song_name, unsigned int new_length) : artist_name(new_name),
        year_made(new_year), music_id(new_id), genre(new_genre), song_name(new_song_name), length (new_length) {

}

bool Song::operator==(Song &target) const {
    bool are_equal = true;
    are_equal = are_equal && static_cast<Music>(genre) == static_cast<Music>(target.genre);
    are_equal = are_equal && static_cast<Music>(song_name) == static_cast<Music>(target.song_name);
    are_equal = are_equal && static_cast<Music>(length) == static_cast<Music>(target.length);
    are_equal = are_equal && static_cast<Music>(*this) == static_cast<Music>(target);
    return are_equal;

}

string Song::get_genre() {
    return genre;
}

string Song::get_song_name() {
    return song_name;
}

string Song::get_length() {
    return length;
}

// Step3. Playlist class

class Playlist {
    vector<Song> my_playlist;

public:
    bool insert_song(Song& song_info); //ask TA
    Playlist shuffle_songs();
};

bool Playlist::insert_song(Song &song_info) {
    int counter = 0; // counts amount of times an artist appears on the playlist
    bool succeed = true; // true if song can be added to the playlist

    for (int index = 0; index < my_playlist.size(); ++index){

        // check if the song is already in the playlist
        if (my_playlist[index] == song_info){
            succeed = false;
        }

        // else, check if artist already appears on playlist
        else {
            if (my_playlist[index].get_artist() == song_info.get_artist()) {
                counter++;
            }
        }
    }
    if (counter > 2 && succeed) {
        succeed = false;
    }
    return succeed;
}

Playlist Playlist::shuffle_songs() {

}

int main(){

}