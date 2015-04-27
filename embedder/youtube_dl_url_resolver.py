import youtube_dl
from pprint import pprint

def silent_output(message, skip_eol=False, check_quiet=False):
    pass

def get_urls(url):
    ydl = youtube_dl.YoutubeDL({'outtmpl': '%(id)s%(ext)s'})
    ydl.to_stdout = silent_output
    ydl.to_stderr = silent_output

    with ydl:
        result = ydl.extract_info(
            url,
            download=False # We just want to extract the info
        )

    if 'entries' in result:
        # Can be a playlist or a list of videos
        video = result['entries'][0]
    else:
        # Just a video
        video = result

    video_url = video['url']
    return video_url
