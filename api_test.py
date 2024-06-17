import unittest
import requests

class APITestCase(unittest.TestCase):
    BASE_URL = 'https://jsonplaceholder.typicode.com'

    def test_get_posts(self):
        response = requests.get(f'{self.BASE_URL}/posts')
        self.assertEqual(response.status_code, 200)
        self.assertIsInstance(response.json(), list)

    def test_get_post(self):
        post_id = 1  # Make sure this post_id exists in the API
        response = requests.get(f'{self.BASE_URL}/posts/{post_id}')
        if response.status_code != 200:
            print(f'Failed to get post {post_id}: {response.status_code}, {response.text}')
        self.assertEqual(response.status_code, 200)
        self.assertEqual(response.json()['id'], post_id)

    def test_create_post(self):
        new_post = {
            'title': 'foo',
            'body': 'bar',
            'userId': 1
        }
        response = requests.post(f'{self.BASE_URL}/posts', json=new_post)
        self.assertEqual(response.status_code, 201)
        self.assertEqual(response.json()['title'], new_post['title'])

if __name__ == '__main__':
    unittest.main()
