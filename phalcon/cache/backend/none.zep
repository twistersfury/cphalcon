
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Cache\Backend;

use Phalcon\Cache\BackendInterface;
use Phalcon\Cache\FrontendInterface;

/**
 * Phalcon\Cache\Backend\None
 *
 * Cache backend that discards all passed data (Disables Caching Completely).
 *
 *<code>
 * use Phalcon\Cache\Backend\None;
 * use Phalcon\Cache\Frontend\None as Frontend;
 *
 * // Create an output cache
 * $frontCache = Frontend([]);
 *
 * // Create the backend
 * $cache = new None($frontCache, []);
 *
 * $content = $cache->start("my-cache");
 *
 * if ($content === null) {
 *     echo "<h1>", time(), "</h1>";
 *
 *     $cache->save();
 * } else {
 *     echo $content;
 * }
 *</code>
 */
class None implements BackendInterface
{
	/**
	 * Frontend
	 */
	private frontEnd;

	/**
 	 * Config
     */
	private options;

	/**
	 * Phalcon\Cache\Backend\None constructor
	 */
	public function __construct(FrontendInterface frontEnd, options = null)
	{
		let this->frontEnd = frontEnd;
		let this->options  = options;
	}

	/**
	 * Return Options
	 *
	 * Maintaining Backwards Compatability
     */
	public function getOptions()
	{
		return options;
	}

	public function start(keyName, lifetime = null)
	{
		//...Yup...Nothing...
	}

	public function stop(stopBuffer = true)
	{
		//Still Nothing
	}

	public function isFresh() -> boolean
	{
		return false;
	}

	public function isStarted()  -> boolean
	{
		return false;
	}

	/**
	 * Returns a cached content
	 */
	public function get(string keyName, int lifetime = null) -> var | null
	{
		//Nothing To Return
		return null;
	}

	/**
	 * Stores cached content into the file backend and stops the frontend
	 *
	 * @param int|string keyName
	 * @param string content
	 * @param int lifetime
	 * @param boolean stopBuffer
	 */
	public function save(var keyName = null, var content = null, lifetime = null, boolean stopBuffer = true) -> boolean
	{
		//Discard Information, But Return True For Consistency.
		return true;
	}

	/**
	 * Deletes a value from the cache by its key
	 *
	 * @param int|string keyName
	 */
	public function delete(var keyName) -> boolean
	{
		return false;
	}

	/**
	 * Query the existing cached keys.
	 *
	 * <code>
	 * $cache->save("users-ids", [1, 2, 3]);
	 * $cache->save("projects-ids", [4, 5, 6]);
	 *
	 * var_dump($cache->queryKeys("users")); // ["users-ids"]
	 * </code>
	 */
	public function queryKeys(string prefix = null) -> array
	{
		//All Keys Are Discarded Anyways.
		return [];
	}

	/**
	 * Checks if cache exists and it isn't expired
	 *
	 * @param string|int keyName
	 * @param int lifetime
	 */
	public function exists(var keyName = null, int lifetime = null) -> boolean
	{
		//Nope.
		return false;
	}
}
