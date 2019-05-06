<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Session\Adapter\Stream;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\SessionTrait;
use function file_put_contents;
use function uniqid;

/**
 * Class DestroyCest
 */
class DestroyCest
{
    use DiTrait;
    use SessionTrait;

    /**
     * @param IntegrationTester $I
     */
    public function _before(IntegrationTester $I)
    {
        $this->newFactoryDefault();
    }

    /**
     * Tests Phalcon\Session\Adapter\Stream :: destroy()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionAdapterStreamDestroy(IntegrationTester $I)
    {
        $I->wantToTest('Session\Adapter\Stream - destroy()');
        $adapter = $this->getSessionStream();

        /**
         * Create a file in the session folder
         */
        file_put_contents(outputSessionsDir('/test1'), uniqid());
        $actual = $adapter->destroy('test1');
        $I->assertTrue($actual);

        $I->amInPath(outputSessionsDir());
        $I->dontSeeFileFound('test1');
    }
}
